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

// typedef	struct 	s_clip
// {
// 	char		*ssignal;
// 	char		*lsignal;
// 	char		*sflags;
// 	char		*valid_sflags;
// 	char		*lflags;
// 	char		*valid_lflags[2];
// 	char		**args;	
// 	int			(*arg_validator)(char*);	
// 	void		(*sflags_apply[6]) (struct 	s_clip *, t_context *);
// 	void		(*lflags_apply[2]) (struct 	s_clip *, t_context *);
// 	void		(*error)(int, char*);

// }				t_clip;

typedef	struct 	s_farm
{
	int		num_ants;
	char	*map;
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

int				syntax_link(char *line);
int				syntax_room(char *line);


# include											<stdio.h>
#endif



