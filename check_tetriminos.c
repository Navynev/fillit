/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:52:15 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/03 16:04:15 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

/*
 ** >> This fct's goal is to check if each (#) of the Tetrimino
 ** is adjacent to another (#).
 ** >> We also check if the number of points of contact between each (#) :
 ** is weather 3 (shapes: S, Z, T, J, L, I),
 ** or 4 (a square shape)
 */

int	hashtag_adjacent(char *tetrimino)
{
	int i;
	int contact;

	i = 0;
	contact = 0;
	while (i < 20)
	{
		if (tetrimino[i] == '#')
		{
			if (tetrimino[i + 1] == '#')
				contact++;
			if (tetrimino[i + 5] == '#')
				contact++;
		}
		i++;
	}
	printf("[PTS DE CONTACT = %d]\n", contact);
	if (contact == 3 || contact == 4)
		return (1);
	else
		return (0);
}

/*
 ** >> This fct's goal is to check the conformity of each piece:
 ** 4 lines, 4 (#), 3 (\n) and 12 (.)
 */

int		piece_conformity(char *tetrimino)
{
	int i;
	int hashtag;
	int line;

	i = 0;
	hashtag = 0;
	line = 0;
	while ((tetrimino[i] == '#' || tetrimino[i] == '.' || tetrimino[i] == '\n')
		  && tetrimino[i] != '\0' && i < 21)
	{
		if (tetrimino[i] == '#')
			hashtag++;
		if ((1 + i) % 5 == 0 && tetrimino[i] == '\n')
			line++;
		i++;
	}
	if (hashtag == 4  /*&& line == 4*/ && hashtag_adjacent(tetrimino))
		return (1);
	return (0);
}

/*
  Check if file contains blocks made of 4 lines with only one '\n'
  between them.
 */
int		check_general_conformity(int fd)
{
	char	*line;
	int		res;
	int		i;

	i = 1;
	line = ft_strdup("");
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if ((i % 5 == 0) && line[0] != 0)
			return (0);
		if ((i % 5 != 0) && ft_strlen(line) != 4)
			return (0);
		++i;
		if (i > 130)
			return (0);
	}
	if (*line == 0)
		return (0);
	printf("%d block(s)\n", i / 5);
	return (i / 5);
}

char	**get_megablock(int fd, int block_nb, int endl)
{
	char	**tetris;
	char	*block;
	int		i;
	int		j;
	char	*line;
	char	*tmp;

	tetris = (char **)malloc(sizeof(char *) * block_nb);
	j = 0;
	i = 1;
	line = ft_strdup("");
	while (j < (block_nb))
	{
		block = ft_strdup("");
		while ((get_next_line(fd, &line) > 0) && (i % 5 != 0) && i++)
		{
			tmp = block;
			if (endl)
				line = ft_strjoin(line, "\n");
			block = ft_strjoin(block, line);
			free(tmp);
		}
		tetris[j] = ft_strdup(block);
		free(block);
		i++;
		j++;
	}
	return (tetris);
}

/*int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*tetri;
	int		block_nb;
	char	**megablock;
	int		i;

	i = 0;
	(void)argc;
	line = ft_strdup("");
	tetri = ft_strdup("");
	fd = open((argv[1]), O_RDONLY);
	if (!(block_nb = check_general_conformity(fd)))
	{
		printf("error in check_general_conformity\n");
		return (0);
	}
	close(fd);
	fd = open((argv[1]), O_RDONLY);
	megablock = get_megablock(fd, block_nb, 1);
	while (i < block_nb)
	{
		if (piece_conformity(megablock[i]))
			printf("Tetrimino %d is valid\n", i + 1);
		else
			printf("Tetrimino %d is not valid\n", i + 1);
		i++;
	}
	return (0);
}*/
