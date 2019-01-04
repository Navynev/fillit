/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:49:01 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/04 12:08:10 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This fct's goal is to return the minimum square dimension size,
** given the number of tetri in the fd
*/

int	get_min_size(int tetri_nb)
{
	int	size;

	size = 2;
	while (tetri_nb * 4 > size * size)
		size++;
	return (size);
}

/*
** This fct allocates memory and fill a fresh square with dots, given the
** square dimension size
*/

int		allocate_square(char ***square, int size)
{
	int	i;
	int	j;

	i = 0;
	if (!(*square = (char **)malloc(sizeof(char *) * size)))
		return (0);
	while (i < size)
	{
		j = 0;
		if (!((*square)[i] = ft_strnew(size)))
			return (0);
		while (j < size)
		{
			(*square)[i][j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;
	int i;
	int size;
	int tetri_nb;
	char **square;

	fd = open((argv[1]), O_RDONLY);
	i = 0;
	tetri_nb = 0;
	tetri_nb = check_general_conformity(fd);
	size = get_min_size(tetri_nb);
	square = NULL;
	(void)argc;
	printf("size = '%d\n", size);
	allocate_square(&square, size);
	while (i < size)
	{
		printf("%s\n", square[i]);
		i++;
	}
	return (0);
}