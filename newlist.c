/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:52:39 by nflores           #+#    #+#             */
/*   Updated: 2015/12/14 12:50:24 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		addtetri(t_tetrilist **lst, t_tetrilist *new)
{
	t_tetrilist	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_tetrilist		*newtetri(char *file, int pos)
{
	t_tetrilist *ret;
	int			i;

	ret = (t_tetrilist *)malloc(sizeof(t_tetrilist));
	if (!ret || file[0] == '\0')
		return (NULL);
	i = 0;
	while (i < 20)
	{
		ret->tetriminos[i] = file[i];
		i++;
	}
	ret->tetriminos[i] = '\0';
	ret->pos = pos;
	ret->next = NULL;
	return (ret);
}

void			newlist(t_tetrilist **lst, char *file)
{
	int				i;
	int				pos;

	i = 0;
	pos = 1;
	if (file[0] != '\0')
	{
		while (file[i] != '\0')
		{
			addtetri(lst, newtetri(file + i, pos));
			if (file[i + 20] == '\0')
				i += 20;
			else
				i += 21;
			pos++;
		}
	}
}
