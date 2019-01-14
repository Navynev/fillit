#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 17:01:23 by jbrisset          #+#    #+#              #
#    Updated: 2019/01/14 17:09:42 by jbrisset         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit
HEADER		=	fillit.h
SRC			=	check_and_read.c\
				fill_item.c\
				set_item.c\
				manage_board.c\
				main.c\
OBJ			=	$(SRC:%.c=%.o)
FLAGS		=	-Wall -Wextra -Werror
RM			=	/bin/rm -f

$(NAME)	:		$(OBJ) $(HEADER)
				gcc $(FLAGS) -c

clean	:
				@(cd $(DIROBJ) && $(RM) $(OBJ))
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) clean)
endif
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
ifdef SUB_MAKE
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
endif
				-@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

%.o		:		$(DIRSRC)/%.c
				$(CC) $(INCLUDE) $(CFLAGS) -o $(DIROBJ)/$@ -c $<
