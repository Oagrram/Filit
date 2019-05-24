# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 02:00:08 by aymhabib          #+#    #+#              #
#    Updated: 2019/05/21 00:51:20 by aymhabib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft.a

SRC = *.c

LIBSRC = libft/*.c

INCLDS = *.h

LIBINCLDS = libft/*.h

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB)
		gcc $(FLAG) $(SRC) $(LIB) -o $(NAME)

$(LIB):
		gcc $(FLAG) -c $(LIBSRC) -I $(LIBINCLDS)
		ar rc $(LIB) ft_*.o

clean:
		/bin/rm -f *.o
		/bin/rm -rf .DS_Store

fclean: clean
		/bin/rm -f $(NAME)
		/bin/rm -f $(LIB)

re: fclean all
