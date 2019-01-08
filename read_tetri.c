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

int	read_tetri(int fd)
{
	int			ret;
	char		buf[22];
	int			i;

	i = 0;
	while ((ret = read(fd, buf, 21)))
	{
		// printf("dans la boucle read %d\n", i);
		if ((ret == 21 && (buf[ret] == '.' || buf[ret] == '#')) || (ret == 20 && buf[19] == '\0'))
		{
			printf("Valeur de RET = [%d]\n", ret);
			buf[ret] = '\0';
			//printf("je suis dans le 1er if\n");
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
	}
	printf("VALEUR DE I AVANT RETURN %d\n", i);
	return (i);
}

int main(int argc, char **argv)
{
	int fd;

	(void)argc;
	fd = open((argv[1]), O_RDONLY);
	printf("%d\n", read_tetri(fd));
	close(fd);
	return (0);
}