/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:59:48 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/12/23 17:07:25 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	fillit_piece;

	if (argc != 2)
	{
		ft_pustr("usage: source file missing\n");
	if ((fillit_piece = read(open(argv[1], O_RDONLY))) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
		
