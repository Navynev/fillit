#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 17:01:23 by jbrisset          #+#    #+#              #
#    Updated: 2019/01/15 10:44:04 by ndelhomm         ###   ########.fr        #
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
	gcc $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(HEADER) -c  $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean	: clean
	/bin/rm -f $(NAME)


re		: fclean all

.PHONY	: all clean fclean re
