/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:14:37 by tde-roqu          #+#    #+#             */
/*   Updated: 2015/12/16 10:52:57 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	checkin(char *map, int *pos, char *tetri, int *j)
{
	int	p;
	int i;

	p = *pos;
	i = *j;
	while (map[p] != '\n' && tetri[i] == '\n')
		p++;
	while (map[p] == '\n' && tetri[i] != '\n')
		i++;
	*pos = p;
	*j = i;
}

int			checkblock(char *map, char *tetri, int pos, int line)
{
	int i;
	int	j;
	int cmp;

	i = pos % (line + 1);
	cmp = 0;
	j = -1;
	while (tetri[++j] != '#')
		i--;
	while (map[pos] != '\0' && tetri[j] != '\0')
	{
		if (map[pos] != '.' && tetri[j] == '#')
			return (2);
		if (map[pos] == '.' && tetri[j] == '#')
			cmp++;
		checkin(map, &pos, tetri, &j);
		if (map[pos] == '\n')
			pos = pos + i;
		pos++;
		j++;
		if (cmp == 4)
			return (1);
	}
	return (0);
}

int			putblock(char *map, t_tetrilist *lst, int pos, int line)
{
	int i;
	int j;

	i = pos % (line + 1);
	j = -1;
	if (checkblock(map, lst->tetriminos, pos, line) == 1)
	{
		while (lst->tetriminos[++j] != '#')
			i--;
		while (map[pos] != '\0' && lst->tetriminos[j] != '\0')
		{
			if (map[pos] == '.' && lst->tetriminos[j] == '#')
				map[pos] = 65 + lst->pos;
			while (map[pos] != '\n' && lst->tetriminos[j] == '\n')
				pos++;
			while (map[pos] == '\n' && lst->tetriminos[j] != '\n')
				j++;
			if (map[pos] == '\n')
				pos = pos + i;
			j++;
			pos++;
		}
		return (1);
	}
	return (0);
}

void		delblock(char *map, t_tetrilist *lst)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == lst->pos + 'A')
			map[i] = '.';
		i++;
	}
}
