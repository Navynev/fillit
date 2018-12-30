/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:51:07 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/18 11:57:12 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int sign;

	i = 0;
	n = 0;
	sign = 0;
	while ((str[i] == ' ') || (str[i] == '\f') ||
			(str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == '\n') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (sign == 1)
		return (-n);
	else
		return (n);
}
