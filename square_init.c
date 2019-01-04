/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:46:21 by jbrisset          #+#    #+#             */
/*   Updated: 2019/01/04 12:46:01 by ndelhomm         ###   ########.fr       */
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
	return (i);
}

t_item tetri_to_item(char *str)
{
	int	i;
	t_item item;

	i = 0;
	while (str[i] && i++)
	{
		if (i % 4 == 0 && j++)
			ft_strncpy(item.tetri[j], str[i], 4);
	}

}

int	megablock_to_items(char **megablock, int block_nb)
{
	t_item	item;
	int		i;

	i = 0;
	while (i < block_nb && i++)
	{
		if (piece_conformity(megablock[i]))
			item = tetri_to_item(megablock[i]);
		else
			return (0);
	}

}

/*int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*tetri;
	int		block_nb;
	char	**megablock;
	int		i;
	int		error;
	char	**square;

	error = 0;
	i = 0;
	square = NULL;
	(void)argc;
	line = ft_strdup("");
	tetri = ft_strdup("");
	fd = open((argv[1]), O_RDONLY);
	if (!(block_nb = 10))
	{
		printf("error in file conformity\n");
		return (0);
	}
	close(fd);
	fd = open((argv[1]), O_RDONLY);
	megablock = get_megablock(fd, block_nb, 0);
	close(fd);
	while (i < block_nb)
	{
		if (!(piece_conformity(megablock[i])))
			error++;
		i++;
	}
	if (error)
		printf("error in tetriminos");
	
	printf("%d\n", get_min_size(block_nb));
	allocate_square(&square, get_min_size(block_nb));
	while (i < get_min_size(block_nb))
	{
		printf("%s\n", square[i]);
		i++;
	}
	return (0);
}*/
