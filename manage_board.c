/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:46:21 by jbrisset          #+#    #+#             */
/*   Updated: 2019/01/14 15:37:52 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Allocates memory and fill a fresh square with dots, given the square
** dimension size.
*/

int		allocate_board(char ***board, int size)
{
	int	i;
	int	j;

	i = 0;
	if (!(*board = (char **)malloc(sizeof(char *) * size)))
		return (0);
	while (i < size)
	{
		j = 0;
		if (!((*board)[i] = ft_strnew(size)))
			return (0);
		while (j < size)
		{
			(*board)[i][j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}

void	free_board(char ***board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&(*board)[i]);
		i++;
	}
}

/*
** Check if the tetriminos will fit in the board creating
** a relative rectangle in the board, of height and width
** of the given tetriminos.
*/

int		block_fit(char **board, int index, int l, int c)
{
	int	i;
	int	j;
	int sz;

	i = 0;
	j = 0;
	sz = ft_strlen(board[0]);
	if (t_items[index].width > (sz - c) || t_items[index].height > (sz - l))
		return (0);
	while (i < t_items[index].height)
	{
		j = 0;
		while (j < t_items[index].width)
		{
			if (t_items[index].tetri[i][j] != '.' && board[l + i][c + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		place_item(char ***board, int index, int l, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < t_items[index].height)
	{
		j = 0;
		while (j < t_items[index].width)
		{
			if (t_items[index].tetri[i][j] != '.')
				(*board)[l + i][c + j] = t_items[index].tetri[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

void	remove_item(char ***board, int size, int item_index)
{
	int		i;
	int		j;
	char	c;

	c = item_index + 65;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((*board)[i][j] == c)
				(*board)[i][j] = '.';
			j++;
		}
		i++;
	}
}
