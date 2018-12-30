/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 07:35:35 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/16 08:48:42 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *copy_string;

	if (!(copy_string =
		(char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (0);
	else
		ft_strcpy(copy_string, s1);
	return (copy_string);
}
