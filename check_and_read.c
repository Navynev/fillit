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

/*
 ** This fct's goal is to check if each (#) of the Tetrimino
 ** is adjacent to another (#).

 ** We also check if the number of points of contact between each (#) :
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
	// printf("[PTS DE CONTACT = %d]\n", contact);
	if (contact == 3 || contact == 4)
		return (1);
	else
		return (0);
}

/*
 ** This fct's goal is to check the conformity of each piece:
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
	if (hashtag == 4  && line == 4 && hashtag_adjacent(tetrimino))
		return (1);
	return (0);
}

/*
** Check if file contains blocks made of 4 lines with only one '\n'
** between them.
*/

int		check_general_conformity(char *file)
{
	char	*line;
	int		res;
	int		i;
	int		fd;

	i = 1;
	line = ft_strdup("");
	fd = open(file, O_RDONLY);
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
	// printf("%d block(s)\n", i / 5);
	close(fd);
	return (i / 5);
}

/*
** Read, check and count all the tretris in the fd
*/

int	read_tetri(char *file)
{
	char	buf[21];
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 21))
	{
		buf[20] = '\0';
		if (piece_conformity(buf))
		{
			// printf("________\n");
			// printf("%s", buf);
			// printf("________\n");
			// printf("VALEUR DE I [%d]\n", i);
			fill_item(buf, i);
			i++;
		}
		else
			return (0);
	}
	close(fd);
	// printf("VALEUR DE I AVANT RETURN %d\n", i);
	return (i);
}

int	check_and_read(char *file)
{
	if (!(check_general_conformity(file)))
		return (0);
	return (read_tetri(file));
}