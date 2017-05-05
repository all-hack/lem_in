/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infa_t_farm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:12:47 by obelange          #+#    #+#             */
/*   Updated: 2017/01/19 20:12:48 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_farm	*t_farm_build()
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
	// farm->presentation_path = NULL;
	// farm->filename = NULL;
	// farm->pre_seed = NULL;
	return (farm);
}

void	t_farm_print(t_farm *farm)
{
	// int i;

	// i = 0;
	ft_printf("\n");
	ft_printf("t_farm:\n");
	ft_printf("farm->num_ants: %d\n", farm->num_ants);
	ft_printf("farm->start: %s\n", farm->start);
	ft_printf("farm->end: %s\n", farm->end);
	ft_printf("farm->map:\n%s", farm->map);
	t_rooms_print(farm->spawns);
	// ft_printf("farm->index: %d\n", farm->index);
	// ft_printf("farm->chr: %s\n", farm->chr);
	// if (farm->invalid)
	// 	while (farm->invalid[i])
	// 	{
	// 		ft_printf("farm->invalid[%d]: %s\n", i, farm->invalid[i]);
	// 		i++;
	// 	}
}

t_farm	*t_farm_init(t_farm *farm)
{
	if (farm)
	{
		// farm->blah = 4;
		// if (index == -1)
		// 	farm->index = 1;
		// else
		// 	farm->index = index;

		// if (chr)
		// 	farm->chr = chr;
		// else
		// 	farm->chr = ".";
		// return (farm);
	}
	// t_farm_destroy(&farm);
	return (NULL);
}

void	t_farm_destroy(t_farm **farm)
{
	if (farm)
	{
		if (*farm)
		{
			ft_strdel(&(*farm)->map);
			t_room_destroy_all(&(*farm)->spawns);
			free(*farm);
			*farm = NULL;
		}
	}
}
