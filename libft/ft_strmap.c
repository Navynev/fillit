/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:07:03 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/18 12:47:55 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh_s;
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	if (!str || !f)
		return (0);
	if (!(fresh_s = (char *)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (0);
	while (str[i])
	{
		fresh_s[i] = f(str[i]);
		i++;
	}
	fresh_s[i] = '\0';
	return (fresh_s);
}
