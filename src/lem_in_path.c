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

int	find_path(t_farm *farm, char *room)
{
	int		i;
	t_room	*curr;
	int		ret;

	
	curr = t_room_get(farm->spawns, room);
	i = ft_strlist_len(curr->connections);

	if (ft_strlist_findindex(curr->connections, farm->end) > -1)
	{
		farm->path = ft_strlist_add(farm->path, room);
		farm->path = ft_strlist_add(farm->path, farm->end);
		return (1);
	}

	// printf("room: %s\n", room);
	// printf("find_path:\n");
	// ft_strlist_print(farm->path);

	while(--i >= 0)
	{
		// printf("i: %d\n", i);		
		if (ft_strlist_findindex(farm->path, curr->connections[i]) == -1)
		{
			farm->path = ft_strlist_add(farm->path, room);
			// printf("_find_path:\n");
			// ft_strlist_print(farm->path);			
			if (find_path(farm, curr->connections[i]) == 1)
			{
				// farm->path = ft_strlist_add(farm->path, curr->connections[i]);
				// farm->path = ft_strlist_add(farm->path, farm->end);
				return (1);
			}
			else
				farm->path = ft_strlist_remove(farm->path, room);
		}
		// printf("term\n");
	}
	return (0);
}





int	waxing_state(t_farm *farm, int path_i, int trailing_ant, int *end_ants)
{
	t_room *room;

	room = t_room_get(farm->spawns, farm->path[path_i]);
	if (trailing_ant > 1)
	{
		if (waxing_state(farm, path_i + 1, trailing_ant - 1, end_ants) == 1)
			ft_printf(" ");
	}
	else if (ft_strcmp(farm->end, room->name) == 0)
		*end_ants = 1;
		
	ft_printf("L%d-%s", trailing_ant, room->name);
	return (1);
}


int	waning_state(t_farm *farm, int path_i, int trailing_ant, int edge)
{
	t_room *room;

	// printf("path_i: %d\n", path_i);
	if (path_i >= edge)
		return (0);

	room = t_room_get(farm->spawns, farm->path[path_i]);
	
	if (path_i < edge)
		if(waning_state(farm, path_i + 1, trailing_ant - 1, edge) == 1)
			ft_printf(" ");
	
	ft_printf("L%d-%s", trailing_ant, room->name);


	return (1);
}


int	constant_state(t_farm *farm, int path_i, int trailing_ant, int edge)
{
	t_room *room;

	room = t_room_get(farm->spawns, farm->path[path_i]);
	
	if (path_i < edge)
		if(waning_state(farm, path_i + 1, trailing_ant - 1, edge) == 1)
			ft_printf(" ");
	
	ft_printf("L%d-%s", trailing_ant, room->name);
	return (1);

}



void	move_ants(t_farm *farm)
{
	int	end_ants;
	int	edge;
	int	trailing_ant;

	end_ants = 0;
	edge = ft_strlist_len(farm->path);
	trailing_ant = 1;

	// printf("ants: %d\n", farm->num_ants);
	// printf("edge: %d\n", edge);

	while (end_ants < farm->num_ants)
	{
		if (end_ants == 0)
		{
			if (waxing_state(farm, 0, trailing_ant++, &end_ants) == 1)
				ft_printf("\n");
		}
		else if (end_ants > 0 && farm->num_ants - end_ants > edge)
		{
			constant_state(farm, 0, trailing_ant, edge);
			// printf("constant state trailing(%d), end(%d)\n", trailing_ant, end_ants);
			ft_printf("\n");
			trailing_ant++;
			end_ants++;
		}
		else if (farm->num_ants - end_ants <= edge)
		{
			// printf("down state -> num(%d) - end(%d): %d", farm->num_ants, end_ants, farm->num_ants - end_ants);
			// printf(" trailing(%d)\n", trailing_ant);
			waning_state(farm, edge - (farm->num_ants - end_ants), trailing_ant, edge);
			ft_printf("\n");
			end_ants++;
		}
		
		// trailing_ant++;
		// if (trailing_ant > 10)
		// 	break;
	}
}


