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

void print_board(char **board, int size)
{
    int i;
    
    i = 0;
    while (i < size)
    {
        ft_putstr(board[i]);
        ft_putchar('\n');
        i++;
    }
}

int resolve(char ***board, int index, int item_nb, int size)
{
    int l;
    int c;
    static int finish;

    l = 0;
    while (l < size && finish == 0)
    {
        c = 0;
        while (c < size && finish == 0)
        {
            if (block_fit(*board, index, l, c, size))
            {
                place_item(board, index, t_items[index].l, t_items[index].c);
                if (index == item_nb - 1)
                    finish = 1;
                resolve(board, index + 1, item_nb, size);
            }
        c++;
        }
    l++;
    }
    if (!finish && !index)
        return (0);
    if (!finish)
        remove_item(board, size, index - 1);
    return (1);
}

int main(int argc, char **argv)
{
    (void)argc;
    int block_nb;
    char **board;
    int size;

    board = NULL;
    if (!(block_nb = check_and_read(argv[1])))
        return (0);
    size = get_min_size(block_nb);
    allocate_square(&board, size);
    while (resolve(&board, 0, block_nb, size) == 0)
    {
        free_board(&board, size);
        allocate_square(&board, ++size);
    }
    print_board(board, size);
    return (0);
}