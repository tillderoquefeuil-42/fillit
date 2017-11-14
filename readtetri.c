/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:47:09 by nflores           #+#    #+#             */
/*   Updated: 2015/12/07 16:51:05 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUF 1024

static int			openfile(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "open error\n", 11);
		exit(0);
	}
	return (fd);
}

char				*readtetri(char *path)
{
	int		fd;
	int		rd;
	int		i;
	char	buf[BUF];
	char	*ret;

	fd = openfile(path);
	rd = read(fd, buf, BUF);
	if (rd == -1)
	{
		write(2, "read error \n", 11);
		exit(0);
	}
	if (!(ret = (char *)malloc(sizeof(char) * rd + 1)))
		exit(0);
	i = 0;
	while (i < rd)
	{
		ret[i] = buf[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
