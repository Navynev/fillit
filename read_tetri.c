/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:21:40 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/08 13:37:36 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


/*
** Read, check and count all the tretris in the fd
*/

int	read_tetri(char *file)
{
	int		ret;
	char	buf[22];
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, 21)))
	{
		buf[20] = '\0';
		if (piece_conformity(buf))
		{
			printf("________\n");
			printf("%s", buf);
			printf("________\n");
			i++;
			printf("VALEUR DE I [%d]\n", i);
			//create_items(buf, i - 1);
		}
		else
			return (0);
	}
	close(fd);
	printf("VALEUR DE I AVANT RETURN %d\n", i);
	return (i);
}

int	check_and_read(char *file)
{
	if (!(check_general_conformity(file)))
		return (0);
	return (read_tetri(file));
}

int main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", check_and_read(argv[1]));
	return (0);
}