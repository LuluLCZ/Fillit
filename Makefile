# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:29:27 by llacaze           #+#    #+#              #
#    Updated: 2017/11/13 12:28:50 by llacaze          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

OPTIONS = -c

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = 	ft_buf_to_tab.c		\
		ft_check_tetri.c	\
		ft_erreurs.c		\
		ft_splitdots_tab.c	\
		main.c

OBJ=$(SRC:.c=.o)

$NAME: $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)
	$(CC) -o $(NAME) $(OBJ)
all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
