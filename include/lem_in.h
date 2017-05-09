/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:06:02 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:06:06 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define BUFF_SIZE 1024
# define NULLGUARD(INPUT) if ((INPUT) == NULL) return (-1)
# define FGUARD(INPUT) if ((INPUT) == -1) return (-1)
# define FILEGUARD(INPUT) if ((INPUT) == -1) return (-1)
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libftprintf.h>
# include "libft.h"

typedef	struct 	s_room
{
	char	*name;
	struct s_room *nxt_spawn;
	struct s_room *prv_spawn;
	char	**connections;
}				t_room;

typedef	struct 	s_farm
{
	int		num_ants;
	char	*map;
	char	*start;
	char	*end;
	char	**path;
	t_room	*spawns;
	int		(*parsing[4]) (struct s_farm *farm, int *phase, char *line);
}				t_farm;

typedef struct	s_line_elem
{
	char				*re[5005];
	int					fd;
	int					st[5005];
	int					s[5005];
	int					flag[5005];
	size_t				index;
	char const			*delim;
	struct s_line_elem	*nxt;
	struct s_line_elem	*prev;
}				t_line_elem;

int				ft_chr_count(char *str, char c);

int				get_next_line(const int fd, char **line);
void			helper_error(char *message);
t_farm			*t_farm_build();
void			t_farm_print(t_farm *farm);
t_farm			*t_farm_init(t_farm *farm);
void			t_farm_destroy(t_farm **farm);

int				parse_ants(t_farm *farm, int *phase, char *line);
int				parse_rooms(t_farm *farm, int *phase, char *line);
int				parse_links(t_farm *farm, int *phase, char *line);

void			store_room(t_farm *farm, char *line, int flag);
void			store_link(t_farm *farm, char *left, char *right);

int				syntax_link(char *line);
int				syntax_room(char *line);

t_room			*t_room_build(char *name);
void			t_room_print(t_room *room);
void			t_room_destroy(t_room **room);
void			t_room_add(t_room *head, t_room *room);
void			t_rooms_print(t_room *room);
t_room			*t_room_get(t_room *head, char *name);
int				t_room_valid_link(t_farm *farm, char *start, char *dest);
void			t_room_destroy_all(t_room **room);






# include											<stdio.h>
#endif



