/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:52:15 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/12/30 17:44:15 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


/*
 ** >> This fct's goal is to check if each (#) of the Tetrimino
 ** is adjacent to another (#).
 ** >> We also check if the number of points of contact between each (#) :
 ** is weather 3 (shapes: S, Z, T, J, L, I),
 ** or 4 (a square shape)
 **
 ** >> Le but de cette fct est de checker si chaque (#) du Tetrimino
 ** est adjacent a un autre (#).
 ** >> On va egalement verifier que le nombre de points de contact est :
 ** soit 3 (formes : S, Z, T J, L I), 
 ** soit 4 (forme carre)
 **
 */

int	hashtag_adjacent(char *tetrimino)
{
	int i;
	int contact;

	i = 0;
	contact = 0;
	//printf("[TETRIMINO = %s]\n", tetrimino);
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
 **
 ** >> Le but de cette fct est de checker si chaque piece est conforme :
 ** 4 lignes, 4 (#), 3 (\n) et 12 (.)
 **
 */

int	piece_conformity(char *tetrimino)
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
	if (hashtag == 4 && line == 4 && hashtag_adjacent(tetrimino))
		return (1);
	return (0);
}


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	char	*tetri;
	char	*tmp_tetri;
	char	*tmp_line;

	(void)argc;
	line = ft_strdup("");
	tetri = ft_strdup("");
	fd = open((argv[1]), O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		line = ft_strjoin(line, "\n");
		//tmp_tetri = tetri;
		tetri = ft_strjoin(tetri, line);
		//free(tetri);
	}
	printf("[TETRI = \n%s]\n", tetri);
	printf("YOLO\n");
	if (piece_conformity(tetri))
		printf("Tetrimino is valid\n");
	else
		printf("Tetrimino is not valid\n");
	return (0);
}
