/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 09:48:07 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/20 08:49:03 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memo_zone;

	if (!(memo_zone = (void *)malloc((size) * sizeof(void *))))
		return (0);
	ft_bzero(memo_zone, size);
	return (memo_zone);
}
