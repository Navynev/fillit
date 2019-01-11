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
** Put the tetriminos the higher possible in the square
*/
void up_tetri(char (*tetri)[5][5])
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

/*
** Put the tetriminos the more left possible
*/
void	left_tetri(char (*tetri)[5][5])
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

void	upleft_tetri(char (*tetri)[5][5])
{
	up_tetri(tetri);
	left_tetri(tetri);
}

int get_height(char tetri[5][5])
{
    int i;
    int j;
    int h;

    h = 0;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4 && i < 4)
        {
            if (tetri[i][j] != '.')
            {
                h++;
                i++;
                j = -1;
            }
        j++;
        }
    i++;
    }
    return (h);
}

int get_width(char tetri[5][5])
{
    int i;
    int j;
    int w;

    w = 0;
    i = 0;
    j = 0;
    while (j < 4)
    {
        i = 0;
        while (j < 4 && i < 4)
        {
            if (tetri[i][j] != '.')
            {
                w++;
                j++;
                i = -1;
            }
            i++;
        }
    j++;
    }
    return (w);
}