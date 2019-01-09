/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:52:15 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/03 16:04:15 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void print_tetri(char tetri[5][5])
{
    int i;
    
    i = 0;
    while (i < 4)
    {
        printf("%s\n", tetri[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    (void)argc;
    int block_nb;
    int i;

    i = 0;
    if ((block_nb = check_and_read(argv[1])))
    {
        while (i < block_nb)
        {
            printf("_________\n");
            print_tetri(t_items[i].tetri);
            printf("height = %d\n", t_items[i].height);
            printf("width = %d\n", t_items[i].width);
            printf("x = %d\n", t_items[i].x);
            printf("y = %d\n", t_items[i].y);
            printf("_________\n");
            i++;
        }
    }
    return (0);
}