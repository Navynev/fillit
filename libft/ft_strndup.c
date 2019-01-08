/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 08:42:10 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/08 15:57:33 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy_string;

	if (!(copy_string = (char *)malloc((n + 1) * sizeof(char))))
		return (0);
	else
		ft_strncpy(copy_string, s1, n);
	return (copy_string);
}
