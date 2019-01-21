#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 17:01:23 by jbrisset          #+#    #+#              #
#    Updated: 2019/01/21 11:48:49 by jbrisset         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit

HEADER		=	fillit.h

SRC			=	check_and_read.c\
				fill_item.c\
				set_item.c\
				manage_board.c\
				main.c\

OBJ			= 	$(SRC:%.c=%.o)

FLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	cd libft && make
	gcc $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(HEADER) -c  $< -o $@

clean:
	/bin/rm -f $(OBJ)
	cd libft/ && make clean

fclean	: clean
	/bin/rm -f $(NAME)
	cd libft/ && make fclean

re		: fclean all

.PHONY	: all clean fclean re
