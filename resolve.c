/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:06:24 by nflores           #+#    #+#             */
/*   Updated: 2015/12/15 16:46:20 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*create(int i)
{
	char	*map;
	int		j;
	int		count;

	map = malloc(sizeof(char) * (i * (i + 1) + 1));
	if (!map)
		return (NULL);
	j = 0;
	count = 0;
	while (j < i * (i + 1))
	{
		if (count == i)
		{
			map[j] = '\n';
			count = 0;
		}
		else
		{
			map[j] = '.';
			count++;
		}
		j++;
	}
	map[j] = '\0';
	return (map);
}

int				fuckit(char *map, t_tetrilist *lst, int line)
{
	int pos;
	int	size;

	size = line * (line + 1);
	pos = 0;
	if (lst == NULL)
		return (1);
	while (pos < size)
	{
		if (putblock(map, lst, pos, line) == 1)
		{
			if (fuckit(map, lst->next, line) == 1)
				return (1);
			else
				delblock(map, lst);
		}
		pos++;
	}
	return (0);
}

char			*resolve(t_tetrilist *lst, int line)
{
	char		*map;
	t_tetrilist	*head;

	head = lst;
	if (!lst)
		return (NULL);
	map = create(line);
	while (fuckit(map, lst, line) != 1)
	{
		free(map);
		line++;
		map = create(line);
		lst = head;
	}
	return (map);
}
