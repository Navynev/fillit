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
	size = get_min_size(tetri_nb);
	tetri_nb = check_general_conformity(fd);
	square = NULL;
	(void)argc;
	while (i < size)
	{
		printf("%d\n", allocate_square(&square, size));
		i++;
	}
	return (0);
}
