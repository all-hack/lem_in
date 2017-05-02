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















