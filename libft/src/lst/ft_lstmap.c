/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:09:01 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:16:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		delete_t_list(void *cont, size_t size)
{
	ft_bzero(cont, size);
	free(cont);
}

t_list			*ft_lstmap(t_list *old, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*res;

	if (old == 0)
		return (0);
	list = ft_lstnew(old->content, old->content_size);
	list = f(list);
	if (list == 0)
		return (0);
	res = list;
	while (old->next != 0)
	{
		old = old->next;
		list->next = ft_lstnew(old->content, old->content_size);
		list->next = f(list->next);
		if (list->next == 0)
		{
			ft_lstdel(&res, &delete_t_list);
			return (0);
		}
		list = list->next;
	}
	return (res);
}
