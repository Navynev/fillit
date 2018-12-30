/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:12:27 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/18 11:52:34 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_occ;

	if (ft_strchr(s, c) == '\0')
		return (NULL);
	else
	{
		while (*s != '\0')
		{
			if (*s == c)
				last_occ = (char *)s;
			s++;
		}
		if (*s == c)
			return ((char *)s);
		else
			return (last_occ);
	}
}
