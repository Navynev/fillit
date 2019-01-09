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

void    fill_tetri(char *buf, int index)
{
    int     i;
    int     j;
    int     k;

    i = 0;
    k = 0;
    j = 0;
    while (buf[i])
    {
        if (buf[i] == '\n')
        {
            ft_strncpy(t_items[index].tetri[k], &buf[j], 4);
            t_items[index].tetri[k][4] = '\0';
            k++;
            i++;
            j = i;
        }
    i++;
    }
    upleft_tetri(t_items[index].tetri);
}

void    fill_item(char *buf, int index)
{
    fill_tetri(buf, index);
    t_items[index].height = get_height(t_items[index].tetri);
    t_items[index].width = get_width(t_items[index].tetri);
    t_items[index].x = 4;
    t_items[index].y = 5;
}
