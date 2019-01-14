/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:52:15 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/11 17:37:34 by ndelhomm         ###   ########.fr       */
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

void print_board(char **board)
{
    int i;
    
    i = 0;
    while (i < 4)
    {
        printf("%s\n", board[i]);
        i++;
    }
}

int resolve(char ***board, int item_index, int item_nb, int size)
{
    int l;
    int c;

    l = 0;
    c = 0;
    while (item_index < item_nb)
    {

        if (block_fit((*board), item_index, l, c, size))
        {
            place_item(&board, item_index, l, c);

        }
    item_index++;
    }
}

int main(int argc, char **argv)
{
    (void)argc;
    int block_nb;
    int i;
    char **board;
    int l;
    int c;
    int size;

    if (!(block_nb = check_and_read(argv[1])))
        return (0);
    size = get_min_size(block_nb);
    allocate_square(&board, si)
    resolve(&board, 0, block_nb, size);
    return (0);
}