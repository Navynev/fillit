#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 17:01:23 by jbrisset          #+#    #+#              #
#    Updated: 2019/01/21 11:36:02 by jbrisset         ###   ########.fr        #
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
	make -C libft/
	gcc $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(HEADER) -c  $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean	: clean
	/bin/rm -f $(NAME)
	fclean -C libft/

re		: fclean all

.PHONY	: all clean fclean re
