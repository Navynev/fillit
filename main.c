/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:52:15 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/14 16:28:39 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Get the minimum square dimension size given the number of tetri in the file.
*/

int		get_min_size(int tetri_nb)
{
	int	size;

	size = 2;
	while (tetri_nb * 4 > size * size)
		size++;
	return (size);
}

void	print_board(char **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
		i++;
	}
}

int		resolve(char ***board, int index, int item_nb, int size)
{
	int			l;
	int			c;
	static int	finish;

	l = -1;
	while (l++ < size && !finish)
	{
		c = -1;
		while (c++ < size && !finish)
		{
			if (block_fit(*board, index, l, c))
			{
				place_item(board, index, l, c);
				if (index == item_nb - 1)
					finish = 1;
				resolve(board, index + 1, item_nb, size);
			}
		}
	}
	if (!finish && !index)
		return (0);
	if (!finish)
		remove_item(board, size, index - 1);
	return (1);
}

int		main(int argc, char **argv)
{
	int		block_nb;
	char	**board;
	int		size;

	(void)argc;
	board = NULL;
	if (!(block_nb = check_and_read(argv[1])))
		return (0);
	size = get_min_size(block_nb);
	allocate_board(&board, size);
	while (resolve(&board, 0, block_nb, size) == 0)
	{
		free_board(&board, size);
		allocate_board(&board, ++size);
	}
	print_board(board, size);
	return (0);
}
