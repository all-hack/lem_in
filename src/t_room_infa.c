/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infa_t_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:12:47 by obelange          #+#    #+#             */
/*   Updated: 2017/01/19 20:12:48 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*t_room_build(char *name)
{
	t_room	*room;

	room = NULL;
	if ((room = (t_room*)malloc(sizeof(t_room))) == 0)
		helper_error("Error: failed to mallocate for t_room\n");
	room->name = name;
	room->nxt_spawn = NULL;
	room->prv_spawn = NULL;
	room->connections = NULL;
	return (room);
}

void	t_room_destroy(t_room **room)
{
	if (room)
	{
		if (*room)
		{
			ft_strdel(&((*room)->name));
			ft_strlist_del(&((*room)->connections));
			free(*room);
			*room = NULL;
		}
	}
}

void	t_room_destroy_all(t_room **room)
{
	if (room && *room)
	{
		t_room_destroy_all(&((*room)->nxt_spawn));
		t_room_destroy(room);
	}
}
