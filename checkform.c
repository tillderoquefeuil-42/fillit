/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:10:59 by nflores           #+#    #+#             */
/*   Updated: 2015/12/17 16:08:25 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		voisinlin(char *tetri, int i, int j)
{
	int voisin;

	voisin = 0;
	if (j == 0)
	{
		if (tetri[i * 5 + j + 1] == '#')
			voisin++;
	}
	else if (j == 3)
	{
		if (tetri[i * 5 + j - 1] == '#')
			voisin++;
	}
	else
	{
		if (tetri[i * 5 + j + 1] == '#')
			voisin++;
		if (tetri[i * 5 + j - 1] == '#')
			voisin++;
	}
	return (voisin);
}

static int		voisincol(char *tetri, int i, int j)
{
	int voisin;

	voisin = 0;
	if (i == 0)
	{
		if (tetri[(i + 1) * 5 + j] == '#')
			voisin++;
	}
	else if (i == 3)
	{
		if (tetri[(i - 1) * 5 + j] == '#')
			voisin++;
	}
	else
	{
		if (tetri[(i + 1) * 5 + j] == '#')
			voisin++;
		if (tetri[(i - 1) * 5 + j] == '#')
			voisin++;
	}
	return (voisin);
}

int				checkform(char *tetri)
{
	int i;
	int j;
	int cons;

	i = 0;
	cons = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			if (tetri[i * 5 + j] == '#')
				cons = voisincol(tetri, i, j) + voisinlin(tetri, i, j);
			if (cons >= 2)
				return (1);
			else
				cons = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int				checkinitlng(char *tetri)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (tetri[i] == '\n')
		{
			if (i != 4 && i != 9 && i != 14 && i != 19)
				return (0);
		}
		i++;
	}
	return (1);
}
