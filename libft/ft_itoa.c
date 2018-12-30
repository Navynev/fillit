/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 08:59:50 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/20 14:37:32 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_intlen(int n)
{
	size_t length;

	length = 0;
	if (n == 0)
		length = 1;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char				*ft_itoa(int n)
{
	char			*fresh_s;
	int				length;
	int				length_init;
	int				sign;

	length_init = ft_intlen(n);
	length = ft_intlen(n);
	sign = (n < 0) ? 1 : 0;
	if (!(fresh_s = (char *)malloc((length + 1) * sizeof(char))))
		return (0);
	if (sign == 1)
		fresh_s[0] = '-';
	else if (n == 0)
		fresh_s[0] = '0';
	while (n)
	{
		if (n > 0)
			fresh_s[length - 1] = n % 10 + '0';
		else
			fresh_s[length - 1] = -(n % 10) + '0';
		n = n / 10;
		length--;
	}
	fresh_s[length_init] = '\0';
	return (fresh_s);
}
