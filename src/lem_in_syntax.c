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

int	syntax_link(char *line)
{
	if (ft_chr_count(line, '-') == 1 && ft_chr_count(line, ' ') == 0)
		return (1);
	return (0);
}

int	syntax_room(char *line)
{
	char	**strlist;
	int		i;

	if (ft_chr_count(line, ' ') == 2)
	{
		strlist = ft_strsplit(line, ' ');	
		if (ft_strlist_len(strlist) == 3
			&& ft_strsearch_ov(strlist[1], "-0123456789") 
			&& ft_strsearch_ov(strlist[2], "-0123456789") 
			&& ft_strsearch_ov("-", strlist[0]) == 0)
		{			
			i = 0;
			while (*strlist)
			{				
				ft_strdel(strlist);
				i += 1;
				strlist++;
			}
			free(strlist - i);
			return (1);
		}
	}
	return (0);
}
