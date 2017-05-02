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


void	store_room(t_farm *farm, char *line, int flag)
{
	char	*room;
	
	room = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	
	if (farm->spawns)
		t_room_add(farm->spawns, t_room_build(room));
	else
		farm->spawns = t_room_build(room);
	farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));	
	if (flag == 1)
		farm->start = room;
	else if (flag == 2)
		farm->end = room;	
}




void	store_link(t_farm *farm, char *left, char *right)
{
	t_room	*room;

	room = t_room_get(farm->spawns, left);
	room->connections = ft_strlist_add(room->connections, right);

	room = t_room_get(farm->spawns, right);
	room->connections = ft_strlist_add(room->connections, left);
}







