/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:46:21 by jbrisset          #+#    #+#             */
/*   Updated: 2019/01/11 16:33:21 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Get the minimum square dimension size given the number of tetri in the file.
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
** Allocates memory and fill a fresh square with dots, given the square
** dimension size.
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

int	block_fit(char **board, int item_nb, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (t_items[item_nb].width > (size - x)
		|| t_items[item_nb]. height > (size - y))
		{
			printf("first return 0");
			return (0);
		}
	while (i < t_items[item_nb].height)
	{
		j = 0;
		while (j < t_items[item_nb].width)
		{
			if (t_items[item_nb].tetri[i][j] != '.' && board[x + i][y + j] != '.')
			{
				printf("%c\n", t_items[item_nb].tetri[i][j]);
				printf("i = %d, j = %d\n", i, j);
				return (0);
			
			}
			j++;
		}
	i++;
	}
	t_items[item_nb].x = x;
	t_items[item_nb].y = y;
	return (1);
}

int	place_item(char ***board, int item_nb, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < t_items[item_nb].height)
	{
		i = 0;
		while (i < t_items[item_nb].width)
		{
			// printf("%c - ", t_items[item_nb].tetri[i][j]);
			if (t_items[item_nb].tetri[i][j] != '.')
				(*board)[x + i][y + j] = t_items[item_nb].tetri[i][j];
			i++;
		}
	j++;
	}
	return (1);
}