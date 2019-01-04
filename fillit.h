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

struct item {
	int		height;
	int		width;
	char	tetri[5][5];
	int		x;
	int		y;
};

char	**get_megablock(int fd, int block_nb, int endl);
int		check_general_conformity(int fd);
int		piece_conformity(char *tetrimino);
int		get_min_size(int tetri_nb);
int		allocate_square(char ***square, int size);

struct item items[26];

#endif



















