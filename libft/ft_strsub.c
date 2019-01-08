/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:19:38 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/08 15:35:45 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh_s;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(fresh_s = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	while (i < len)
	{
		fresh_s[i] = s[start + i];
		i++;
	}
	fresh_s[i] = '\0';
	return (fresh_s);
}
