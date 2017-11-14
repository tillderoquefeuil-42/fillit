/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:12:57 by nflores           #+#    #+#             */
/*   Updated: 2015/12/21 10:42:09 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		checklinext(char *tetri, int i, int j)
{
	if (i == 0)
	{
		if (j == 3 && (tetri[(i + 1) * 5 + j] != '#' &&
					tetri[i * 5 + j - 1] != '#'))
			return (0);
		else if (j == 0 &&
				(tetri[(i + 1) * 5 + j] != '#' && tetri[i * 5 + j + 1] != '#'))
			return (0);
		else if (tetri[(i + 1) * 5 + j] != '#' && tetri[i * 5 + j - 1] != '#'
				&& tetri[i * 5 + j + 1] != '#')
			return (0);
	}
	else if (i == 3)
	{
		if (j == 3 && (tetri[(i - 1) * 5 + j] != '#' &&
					tetri[i * 5 + j - 1] != '#'))
			return (0);
		else if (j == 0 && (tetri[(i - 1) * 5 + j] != '#' &&
							tetri[i * 5 + j + 1] != '#'))
			return (0);
		else if (tetri[(i - 1) * 5 + j] != '#' && tetri[i * 5 + j - 1] != '#' &&
				tetri[i * 5 + j + 1] != '#')
			return (0);
	}
	return (1);
}

static int		checkline(char *tetri, int i, int j)
{
	if (j == 0)
	{
		if (tetri[i * 5 + j + 1] != '#' && tetri[(i - 1) * 5 + j] != '#' &&
			tetri[(i + 1) * 5 + j] != '#')
			return (0);
	}
	else if (j == 3)
	{
		if (tetri[i * 5 + j - 1] != '#' && tetri[(i - 1) * 5 + j] != '#' &&
			tetri[(i + 1) * 5 + j] != '#')
			return (0);
	}
	else if (tetri[i * 5 + j - 1] != '#' && tetri[i * 5 + j + 1] != '#' &&
			tetri[(i + 1) * 5 + j] != '#' && tetri[(i - 1) * 5 + j] != '#')
		return (0);
	return (1);
}

static int		checktetriminos(char *tetri)
{
	int i;
	int j;
	int bloc;

	i = 0;
	bloc = 0;
	while (i < 4)
	{
		j = -1;
		while (j++ < 4)
		{
			if (tetri[i * 5 + j] == '#')
			{
				bloc++;
				if ((i == 0 || i == 3) && !checklinext(tetri, i, j))
					return (0);
				else if (!checkline(tetri, i, j))
					return (0);
			}
			if (j == 4 && tetri[i * 5 + j] != '\n')
				return (0);
		}
		i++;
	}
	return (bloc == 4);
}

int				checktetri(char *tetri)
{
	int count;
	int i;

	i = -1;
	if (i == -1 && !checkinitlng(tetri))
		return (0);
	count = 0;
	while (tetri[++i] != '\0')
	{
		if (tetri[i] != '#' && tetri[i] != '.' && tetri[i] != '\n' &&
			tetri[i] != '\0')
			return (0);
		if (tetri[i] == '\n')
			count++;
		if (count % 4 == 0 && count != 0)
		{
			count = -1;
			if (!checktetriminos(tetri + i - 19) || !checkform(tetri + i - 19))
				return (0);
			if (tetri[i + 1] != '.' && tetri[i + 1] != '\0' &&
				tetri[i + 1] != '#' && tetri[i + 1] != '\n')
				return (0);
		}
	}
	return (tetri[i - 1] == '\n' && count == -1);
}

int				miniline(t_tetrilist *lst)
{
	int c;
	int	line;

	line = 2;
	c = 0;
	while (lst != NULL)
	{
		c++;
		lst = lst->next;
	}
	c = c * 4;
	while (c > line * line)
		line++;
	return (line);
}
