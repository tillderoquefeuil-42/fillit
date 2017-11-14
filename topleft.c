/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topleft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:35:02 by nflores           #+#    #+#             */
/*   Updated: 2015/12/14 13:15:05 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			isleft(char *tetri)
{
	int i;
	int pos;
	int line;

	pos = 3;
	line = 0;
	i = 0;
	while (tetri[i + line * 5] != '\0')
	{
		while (tetri[i + line * 5] != '\n')
		{
			if (tetri[i + line * 5] == '#' && i < pos)
			{
				pos = i;
				if (pos == 0)
					return (1);
			}
			i++;
		}
		line++;
		i = 0;
	}
	return (0);
}

static int			istop(char *tetri)
{
	int i;
	int line;

	i = 0;
	line = 0;
	while (tetri[i] != '#')
	{
		if (tetri[i] == '\n')
			line++;
		i++;
	}
	if (line != 0)
		return (0);
	return (1);
}

static void			puttop(char *tetri)
{
	int i;

	while (istop(tetri) != 1)
	{
		i = 0;
		while (tetri[i] != '\0')
		{
			if (tetri[i] == '#')
			{
				tetri[i] = '.';
				tetri[i - 5] = '#';
			}
			i++;
		}
	}
}

static void			putleft(char *tetri)
{
	int i;

	while (isleft(tetri) != 1)
	{
		i = 0;
		while (tetri[i] != '\0')
		{
			if (tetri[i] == '#' && i != 0 && i % 5 != 0)
			{
				tetri[i] = '.';
				tetri[i - 1] = '#';
			}
			i++;
		}
	}
}

void				topleft(t_tetrilist *elem)
{
	t_tetrilist *ret;

	ret = elem;
	if (ret)
	{
		putleft(ret->tetriminos);
		puttop(ret->tetriminos);
	}
}
