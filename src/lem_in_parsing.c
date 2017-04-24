/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:43:04 by obelange          #+#    #+#             */
/*   Updated: 2016/10/27 09:43:07 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse_ants(t_farm *farm, int *phase, char *line)
{
	if (*phase == 0)
	{
		if (ft_strsearch_ov(line, "0123456789"))
		{
			printf("ant parsed\n");
			farm->num_ants = ft_atoi(line);
			*phase = 1;
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
			return (0);
		}
	}
	return (1);
}

