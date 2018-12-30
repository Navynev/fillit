/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:21:11 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/20 19:47:39 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh_list;

	if (lst && f)
	{
		fresh_list = f(lst);
		if (fresh_list != NULL && lst->next != NULL)
			fresh_list->next = ft_lstmap(lst->next, f);
		return (fresh_list);
	}
	return (0);
}
