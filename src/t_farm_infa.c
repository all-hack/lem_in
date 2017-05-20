/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infa_t_farm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:12:47 by obelange          #+#    #+#             */
/*   Updated: 2017/01/19 20:12:48 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_farm	*t_farm_build(void)
{
	t_farm	*farm;

	farm = NULL;
	if ((farm = (t_farm*)malloc(sizeof(t_farm))) == 0)
		helper_error("Error: failed to mallocate for t_farm\n");
	farm->num_ants = -1;
	farm->map = ft_strdup("");
	farm->parsing[0] = parse_ants;
	farm->parsing[1] = parse_rooms;
	farm->parsing[2] = parse_links;
	farm->parsing[3] = NULL;
	farm->start = NULL;
	farm->end = NULL;
	farm->path = NULL;
	farm->spawns = NULL;
	return (farm);
}

void	t_farm_print(t_farm *farm)
{
	ft_printf("\n");
	ft_printf("t_farm:\n");
	ft_printf("farm->num_ants: %d\n", farm->num_ants);
	ft_printf("farm->start: %s\n", farm->start);
	ft_printf("farm->end: %s\n", farm->end);
	ft_printf("farm->map:\n%s", farm->map);
	t_rooms_print(farm->spawns);
}

void	t_farm_destroy(t_farm **farm)
{
	if (farm)
	{
		if (*farm)
		{
			ft_strdel(&(*farm)->map);
			t_room_destroy_all(&(*farm)->spawns);
			ft_strlist_del(&(*farm)->path);
			free(*farm);
			*farm = NULL;
		}
	}
}
