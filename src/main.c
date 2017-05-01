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


void	read_from_stdin(t_farm *farm)
{
	int		phase;
	char	*line;
	int		ret;
	int		i;

	phase = 0;
	i = 0;
	line = NULL;	
	while((get_next_line(0, &line)) > 0)
	{
		printf("\n%s\n", line);
		printf("phase: %d\n", phase);
		ret = 1;
		i = 0;
		while (ret == 1)
			ret = farm->parsing[i++](farm, &phase, line);

		ft_strdel(&line);
		if (ret == -1)
			break;
		// printf("%s\n", line);
		
	}	
}

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
			store_room(farm, line, 1);
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			// printf("end found\n");
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
			ft_strdel(&line);
			get_next_line(0, &line);
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
			printf("link found starting link phase\n");
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
			printf("room error\n");
			return (-1);
		}
	}
	return (1);
}



void	store_link(t_farm *farm, char *left, char *right)
{
	t_room	*room;

	room = t_room_get(farm->spawns, left);
	room->connections = ft_strlist_add(room->connections, right);

	room = t_room_get(farm->spawns, right);
	room->connections = ft_strlist_add(room->connections, left);
}


int		parse_links(t_farm *farm, int *phase, char *line)
{
	char	*left;
	char	*right;

	if (*phase == 2)
	{
		if (*line == '#')
		{
			printf("link comment found\n");
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
		}
		else if (syntax_link(line))
		{
			left = ft_strsub(line, 0, ft_strchr(line, '-') - line);
			right = ft_strdup(line + (ft_strchr(line, '-') - line + 1));
			// t_room_print(farm->spawns);
			if (t_room_valid_link(farm, left, right))
			{
				printf("link parsed\n");
				store_link(farm, left, right);
				farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
				return (0);
			}
		}
		else
		{
			printf("link error\n");
			return (-1);
		}
	}
	return (0);
}






int	main(void){

	t_farm	*farm;

	farm = t_farm_build();
	read_from_stdin(farm);

	// int phase = 2;
	// printf("ret: %d, phase: %d\n", farm->parsing[2](farm, &phase, "room-4"), phase);

	t_farm_print(farm);
	

	// t_room	*a;
	// t_room	*b;
	// t_room	*c;

	// farm->spawns = t_room_build(ft_strdup("fosho"));

	// t_room_print(farm->spawns);

	// a = t_room_build(ft_strdup("swag"));
	// b = t_room_build(ft_strdup("dag"));
	// c = t_room_build(ft_strdup("rag"));

	// printf("farm:\n");
	// t_rooms_print(farm->spawns);
	
	// printf("\nroom a------->\n");
	// t_rooms_print(a);
	// printf("\nroom b------->\n");
	// t_rooms_print(b);
	// printf("\nroom c------->\n");
	// t_rooms_print(c);

	// t_room_add(farm->spawns, a);
	// t_room_add(farm->spawns, b);
	// t_room_add(farm->spawns, c);

	// printf("\nfarm------->\n");
	// t_rooms_print(farm->spawns);

	// printf("valid link: %d\n", t_room_valid_link(farm, "dag", "swag"));

	// t_room_destroy_all(&farm->spawns);




	// printf("room: %p\n", farm->spawns);

	t_farm_destroy(&farm);




}















