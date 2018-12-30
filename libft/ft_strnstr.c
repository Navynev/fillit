/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:57:34 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/20 19:46:51 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_size;
	char	*hay;
	char	*need;

	hay = (char *)haystack;
	need = (char *)needle;
	if (*needle == '\0')
		return (hay);
	i = 0;
	needle_size = ft_strlen(need);
	while (hay[i] && (needle_size + i) <= len)
	{
		if (ft_strncmp(hay + i, need, needle_size) == 0)
			return (hay + i);
		i++;
	}
	return (0);
}
