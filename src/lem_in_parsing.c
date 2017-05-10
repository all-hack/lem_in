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
			// printf("ant parsed\n");
			farm->num_ants = ft_atoi(line);
			*phase = 1;
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
			return (0);
		}
	}
	return (1);
}

int		parse_rooms(t_farm *farm, int *phase, char *line)
{
	if (*phase == 1)
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			// printf("start found\n");
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
			ft_strdel(&line);
			get_next_line(0, &line);
			if (syntax_room(line) == 1)
				store_room(farm, line, 1);
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
			ft_strdel(&line);
			get_next_line(0, &line);
			if (syntax_room(line) == 1)
				store_room(farm, line, 2);
		}
		else if (*line == '#')
		{
			// printf("room comment found\n");
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
		}
		else if (syntax_link(line) == 1)
		{
			*phase = 2;
			// printf("link found starting link phase\n");
			return (1);
		}
		else if (syntax_room(line) == 1)
		{			
			// farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
			store_room(farm, line, 0);
			// printf("%p\n", farm->spawns);
			return (0);
		}
		else
		{
			// printf("room error\n");
			return (-1);
		}
	}
	return (1);
}

int		parse_links(t_farm *farm, int *phase, char *line)
{
	char	*left;
	char	*right;

	if (*phase == 2)
	{
		if (*line == '#')
		{
			// printf("link comment found\n");
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
		}
		else if (syntax_link(line))
		{
			left = ft_strsub(line, 0, ft_strchr(line, '-') - line);
			right = ft_strdup(line + (ft_strchr(line, '-') - line + 1));
			// t_room_print(farm->spawns);
			if (t_room_valid_link(farm, left, right))
			{
				// printf("link parsed\n");
				store_link(farm, left, right);
				farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
				return (0);
			}
		}
		else
		{
			// printf("link error\n");
			return (-1);
		}
	}
	return (0);
}
