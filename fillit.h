/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:47:23 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/04 12:46:09 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

struct	s_item {
	int		height;
	int		width;
	char	tetri[5][5];
	int		x;
	int		y;
}				t_items[26];

int		check_and_read(char *file);
void	fill_item(char *buf, int index);
void	upleft_tetri(char (*tetri)[5][5]);
int 	get_height(char tetri[5][5]);
int 	get_width(char tetri[5][5]);
int		get_min_size(int tetri_nb);
int		allocate_square(char ***square, int size);
void    sharp_to_alpha(char (*tetri)[5][5], int index);

#endif


