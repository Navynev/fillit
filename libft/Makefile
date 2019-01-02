# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:55:00 by ndelhomm          #+#    #+#              #
#    Updated: 2019/01/02 15:13:38 by ndelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Werror -Wextra

SRC = ft_lstdel.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_isascii.c \
	  ft_memalloc.c	\
	  ft_memset.c \
	  ft_putstr.c \
	  ft_strdel.c \
	  ft_strlen.c \
	  ft_strnequ.c \
	  ft_strtrim.c \
	  ft_isdigit.c \
  	  ft_memccpy.c	\
	  ft_putchar.c	\
	  ft_putstr_fd.c\
  	  ft_strdup.c \
  	  ft_strmap.c \
	  ft_strnew.c \
	  ft_tolower.c \
	  ft_isprint.c \
  	  ft_memchr.c \
	  ft_putchar_fd.c \
	  ft_strcat.c \
	  ft_strequ.c \
	  ft_strmapi.c \
	  ft_strnstr.c	\
	  ft_toupper.c \
	  ft_atoi.c \
  	  ft_itoa.c \
  	  ft_memcmp.c \
  	  ft_putendl.c \
  	  ft_strchr.c \
	  ft_striter.c \
	  ft_strncat.c	\
	  ft_strrchr.c \
	  ft_bzero.c \
	  ft_lstadd.c \
	  ft_memcpy.c \
  	  ft_putendl_fd.c \
	  ft_strclr.c \
	  ft_striteri.c \
	  ft_strncmp.c \
	  ft_strsplit.c	\
	  ft_isalnum.c \
	  ft_lstdelone.c \
	  ft_memdel.c \
  	  ft_putnbr.c \
	  ft_strcmp.c \
	  ft_strjoin.c \
  	  ft_strncpy.c \
	  ft_strstr.c \
	  ft_isalpha.c \
	  ft_lstnew.c \
  	  ft_memmove.c \
	  ft_putnbr_fd.c \
  	  ft_strcpy.c \
  	  ft_strlcat.c \
  	  ft_strndup.c \
  	  ft_strsub.c \
	  ft_str_is_lowercase.c \
	  ft_str_is_uppercase.c \
	  ft_str_is_printable.c \
	  ft_str_is_numeric.c \
	get_next_line.c\

HEADER = libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAG) -o $@ $? -I.
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
