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

/*
** Pour tester allocate square
**
*/
// int		main(int argc, char **argv)
// {
// 	int fd;
// 	int i;
// 	int size;
// 	int tetri_nb;
// 	char **square;

// 	fd = open((argv[1]), O_RDONLY);
// 	i = 0;
// 	tetri_nb = 0;
// 	tetri_nb = check_general_conformity(fd);
// 	size = get_min_size(tetri_nb);
// 	square = NULL;
// 	(void)argc;
// 	printf("size = '%d\n", size);
// 	allocate_square(&square, size);
// 	while (i < size)
// 	{
// 		printf("%s\n", square[i]);
// 		i++;
// 	}
// 	return (0);
// }

void up_tetri(char ***tetri)
{
	int	i;
	int	j;
	int	first_hash;
	int line_up;

	i = 0;
	first_hash = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*tetri)[i][j] == '#')
			{
				if (!first_hash)
				{
					first_hash = 1;
					line_up = i;
				}
				(*tetri)[i][j] = '.';
				(*tetri)[i - line_up][j] = '#';
			}
			j++;
		}
		i++;
	}
}

void	left_tetri(char ***tetri)
{
	int i;
	int j;
	int first_hash;
	int column_left;
	
	j = 0;
	first_hash = 0;
	while (j < 4)
	{
		i = 3;
		while (i >= 0)
		{
			if ((*tetri)[i][j] == '#')
			{
				if (!first_hash)
				{
					first_hash = 1;
					column_left = j;
				}
				(*tetri)[i][j] = '.';
				(*tetri)[i][j - column_left] = '#';
			}
		i--;
		}
	j++;
	}
}

void	upleft_tetri(char ***tetri)
{
	up_tetri(tetri);
	left_tetri(tetri);
}

int main(void)
{
	char **tab;

	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("....");
	tab[1] = ft_strdup("....");
	tab[2] = ft_strdup("...#");
	tab[3] = ft_strdup("...#");

	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	upleft_tetri(&tab);
	printf("__________\n");
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	
	/*left_tetri(&tab);
	printf("__________\n");
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);*/
	return (0);
}