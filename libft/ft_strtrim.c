/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:26:54 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/20 13:34:12 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*fresh_s;
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!(fresh_s = (char *)malloc(sizeof(char))) || !s)
		return (0);
	str = (char *)s;
	i = 0;
	j = ft_strlen(s) - 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (ft_strdup(str + i));
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
		j--;
	k = j - i + 1;
	if (!(fresh_s = (char *)malloc((k + 1) * sizeof(char))))
		return (0);
	ft_strncpy(fresh_s, str + i, k);
	fresh_s[k] = '\0';
	return (fresh_s);
}
