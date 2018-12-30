/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:43:12 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/11/20 19:14:19 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_maillon;
	t_list	*next;

	tmp_maillon = *alst;
	if (alst || del)
	{
		while (tmp_maillon)
		{
			next = tmp_maillon->next;
			del(tmp_maillon->content, tmp_maillon->content_size);
			free(tmp_maillon);
			tmp_maillon = next;
		}
		*alst = NULL;
	}
}
