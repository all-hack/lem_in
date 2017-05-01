/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infa_t_room.c                                   :+:      :+:    :+:   */
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
	room->connections = NULL;
	return (room);
}

void	t_room_print(t_room *room)
{
	char **conect;

	ft_printf("\n");
	ft_printf("t_room:\n");
	ft_printf("room->name: %s\n", room->name);
	ft_printf("room->nxt_spawn: %p\n", room->nxt_spawn);
	ft_printf("connections:\n");
	if (room->connections)
	{
		conect = room->connections;
		ft_printf("-> %s\n", *conect);
		while (*++conect)
			ft_printf("-> %s\n", *conect);
	}
	else
		printf("%s\n", "-> none");
}

void	t_rooms_print(t_room *room)
{
	if (room)
		while (room)
		{
			t_room_print(room);
			room = room->nxt_spawn;
		}
	else
		printf("no rooms");
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

void	t_room_add(t_room *head, t_room *room)
{
	if (head && room)
	{
		while (head->nxt_spawn)
			head = head->nxt_spawn;
		head->nxt_spawn = room;
	}
}

t_room	*t_room_get(t_room *head, char *name)
{
	if (head)
	{
		while (head)
		{
			if (ft_strcmp(name, head->name) == 0)
				return (head);
			else
				head = head->nxt_spawn;			
		}
	}
	return (NULL);
}





int		t_room_valid_link(t_farm *farm, char *start, char *dest)
{
	if (start && dest && farm)
	{
		if (t_room_get(farm->spawns, start) && t_room_get(farm->spawns, dest))
			return (1);
	}
	return (0);
}




