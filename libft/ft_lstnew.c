/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:12:15 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/17 11:41:14 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *my_content, size_t content_size)
{
	t_list	*fresh_maillon;

	if (!(fresh_maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!my_content)
	{
		fresh_maillon->content = NULL;
		fresh_maillon->content_size = 0;
	}
	else
	{
		if (!(fresh_maillon->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(fresh_maillon->content, my_content, content_size);
		fresh_maillon->content_size = content_size;
	}
	fresh_maillon->next = NULL;
	return (fresh_maillon);
}
