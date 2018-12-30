/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:58:49 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/12/13 13:44:47 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh_s;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!(fresh_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
		* sizeof(char))))
		return (0);
	ft_strcpy(fresh_s, s1);
	ft_strcat(fresh_s, s2);
	return (fresh_s);
}
