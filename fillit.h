/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:47:23 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/03 15:56:29 by jbrisset         ###   ########.fr       */
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

struct item items[26];

#endif



















