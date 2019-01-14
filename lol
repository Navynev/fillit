# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 11:48:21 by ndelhomm          #+#    #+#              #
#    Updated: 2018/12/21 11:59:49 by ndelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.out
FLAG = -Wall -Werror -Wextra
SRC = check_tetriminos.c main.c
HEADER = fillit.h
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	gcc $(FLAG) -c $(SRC) -I $(HEADER) 
	ar rc $(NAME) $(OBJ)
	/bin/rm -rf $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all