/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:52:15 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/24 14:18:05 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check if each '#' of the Tetrimino is adjacent to another '#'.
** Also check if the number of points of contact between each '#':
** is 3 (shapes: S, Z, T, J, L, I) or 4 (a square shape)
*/

int	hashtag_adjacent(char *tetrimino)
{
	int	i;
	int	contact;

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
	if (contact == 3 || contact == 4)
		return (1);
	else
		return (0);
}

/*
** Check the conformity of each piece: 4 lines, 4 '#',
** 3 '\n' and 12 '.'.
*/

int	piece_conformity(char *tetrimino)
{
	int	i;
	int	hashtag;
	int	line;

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

/*
** Check if file contains blocks made of 4 lines with only one '\n'
** between them.
*/

int	check_general_conformity(char *file)
{
	char	*line;
	int		res;
	int		i;
	int		fd;

	i = 1;
	line = NULL;
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		
		if (((i % 5 == 0) && line[0] != 0) || ((i % 5 != 0) && ft_strlen(line) != 4) || (i > 130))
			return (0);
		++i;
		//free(line);
		//if ((i % 5 != 0) && ft_strlen(line) != 4)
			//return (0);
	}
	if (*line == 0)
		return (0);
	//free(line);
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
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	while (read(fd, buf, 21))
	{
		buf[20] = '\0';
		if (piece_conformity(buf))
		{
			fill_item(buf, i);
			i++;
		}
		else
			return (0);
		ft_bzero(buf, 21);
	}
	close(fd);
	return (i);
}

int	check_and_read(char *file)
{
	if (!(check_general_conformity(file)))
		return (0);
	return (read_tetri(file));
}
