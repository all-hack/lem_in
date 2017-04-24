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

int		parse_rooms(t_farm *farm, int *phase, char *line)
{
	if (*phase == 1)
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			printf("start found\n");
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			printf("end found\n");
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
		}
		else if (*line == '#')
		{
			printf("room comment found\n");
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
			printf("room parsed\n");			
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
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


int		parse_links(t_farm *farm, int *phase, char *line)
{
	if (*phase == 2)
	{
		if (*line == '#')
		{
			printf("link comment found\n");
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
		}
		else if (syntax_link(line))
		{
			printf("link parsed\n");
			farm->map = ft_fstrmcatf(farm->map, ft_strmcat(line, "\n"));
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

	// t_farm_print(farm);
	
}















