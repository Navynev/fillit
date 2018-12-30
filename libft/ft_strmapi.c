/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:26:20 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/18 12:48:39 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh_s;
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	if (!str || !f)
		return (0);
	if (!(fresh_s = malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (0);
	while (s[i])
	{
		fresh_s[i] = f(i, str[i]);
		i++;
	}
	fresh_s[i] = '\0';
	return (fresh_s);
}
