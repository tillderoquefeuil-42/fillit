/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:24:21 by nflores           #+#    #+#             */
/*   Updated: 2015/12/17 16:09:15 by nflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

typedef struct		s_tetrilist
{
	char				tetriminos[21];
	int					pos;
	struct s_tetrilist	*next;
}					t_tetrilist;

char				*readtetri(char *path);
int					checktetri(char *tetri);
t_tetrilist			*newtetri(char *file, int pos);
void				newlist(t_tetrilist **lst, char *file);
void				print_error(void);
char				*resolve(t_tetrilist *lst, int line);
void				topleft(t_tetrilist *elem);
void				lstmap(t_tetrilist *lst);
int					checkform(char *tetri);
int					checkinitlng(char *tetri);
int					checkblock(char *map, char *tetri, int pos, int line);
int					putblock(char *map, t_tetrilist *lst, int pos, int line);
int					remplir(char *map, t_tetrilist *lst, int pos, int line);
void				freelst(t_tetrilist **lst);
void				delblock(char *map, t_tetrilist *lst);
int					miniline(t_tetrilist *lst);

#endif
