#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nflores <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 11:08:10 by nflores           #+#    #+#              #
#    Updated: 2015/12/16 10:57:36 by nflores          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = block.c checkform.c checktetri.c freelst.c lstmap.c newlist.c \
	print_error.c readtetri.c resolve.c topleft.c main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc $(FLAGS) -I libft/includes -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
