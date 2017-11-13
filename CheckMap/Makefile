# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:29:27 by llacaze           #+#    #+#              #
#    Updated: 2017/11/13 13:52:00 by llacaze          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

OPTIONS = -c

CFLAGS = -Wall -Wextra -Werror

LIBFT = includes/Libft/libft.a

RM = rm -f

SRC = 	ft_tetriminos.h	\
		main.c				\
		ft_buf_to_tab.c		\
		ft_check_tetri.c	\
		ft_erreurs.c		\
		ft_splitdots_tab.c	

OBJ=$(SRC:.c=.o)

$NAME: $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OPTIONS) $(LIBFT) $(SRC)
	$(CC) -o $(NAME) $(OBJ)
all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
