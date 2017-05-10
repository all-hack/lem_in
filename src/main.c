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
		ret = 1;
		i = 0;
		while (ret == 1)
		{
			// printf("parse: %d\n", i);
			ret = farm->parsing[i++](farm, &phase, line);
		}
		ft_strdel(&line);
		if (ret == -1)
			break;
	}	
}





int	main(void){

	t_farm	*farm;


	farm = t_farm_build();
	read_from_stdin(farm);

	if (!farm->spawns || !farm->start || !farm->end)
		helper_error("Error\n");
	printf("%s\n", farm->map);

	
	int path_res = -1;
	path_res = find_path(farm, farm->start);
	if (path_res != 1)
		helper_error("Error\n");
	farm->path = ft_strlist_remove(farm->path, farm->start);
	// printf("path found: %d\n", path_res);
	// printf("path-->\n");
	// ft_strlist_print(farm->path);
	// printf("move_ants: \n");
	move_ants(farm);
	


	t_farm_destroy(&farm);




}















