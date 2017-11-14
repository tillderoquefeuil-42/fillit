/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:37:38 by nflores           #+#    #+#             */
/*   Updated: 2015/12/16 11:39:54 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	char			*file;
	char			*map;
	t_tetrilist		*tetri;
	int				minline;

	if (argc != 2)
	{
		write(2, "use : fillit <file>\n", 20);
		return (0);
	}
	file = readtetri(argv[1]);
	if (!checktetri(file))
		print_error();
	tetri = NULL;
	tetri = newtetri(file, 0);
	if (file[20] != '\0')
		newlist(&tetri, file + 21);
	free(file);
	lstmap(tetri);
	minline = miniline(tetri);
	map = resolve(tetri, minline);
	ft_putstr(map);
	free(map);
	freelst(&tetri);
	return (0);
}
