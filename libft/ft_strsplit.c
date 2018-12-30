/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:34:08 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/20 19:00:35 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	char		**tab_of_fresh_s;
	size_t		i;
	size_t		j;
	size_t		size;

	if (!s || !c || !(tab_of_fresh_s = ft_memalloc(ft_strlen(s) + 1)))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			size = 0;
			while (s[i + size] && s[i + size] != c)
				size++;
			tab_of_fresh_s[j++] = ft_strsub(s, i, size);
			i = i + size;
		}
	}
	tab_of_fresh_s[j] = NULL;
	return (tab_of_fresh_s);
}
