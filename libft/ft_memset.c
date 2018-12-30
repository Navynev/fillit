/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:54:39 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/12/10 15:56:58 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*tab;

	c = (unsigned char)c;
	tab = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		tab[i] = c;
		i++;
	}
	return (b);
}
