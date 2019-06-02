# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 02:00:08 by aymhabib          #+#    #+#              #
#    Updated: 2019/05/30 05:33:51 by aymhabib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft.a

SRC = fillit.c print.c split_and_cord.c split_the_tet.c validating.c backtracking.c backtrack_add_func.c

LIBSRC = libft/*.c

INCLDS = fillit.h

LIBINCLDS = libft/libft.h

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB)
		gcc $(FLAG) $(SRC) $(LIB) -o $(NAME)

$(LIB):
		gcc $(FLAG) -c $(LIBSRC) -I $(LIBINCLDS)
		ar rc $(LIB) *.o
clean:
		/bin/rm -f *.o
		/bin/rm -f .DS_Store

fclean: clean
		/bin/rm -f $(NAME)
		/bin/rm -f $(LIB)

re: fclean all
