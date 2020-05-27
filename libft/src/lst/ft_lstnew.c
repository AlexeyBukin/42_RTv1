/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:24:56 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/28 01:01:34 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*content_copy;
	t_list	*res;

	res = (t_list*)malloc(sizeof(t_list));
	if (res == NULL)
	{
		return (NULL);
	}
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		content_copy = ft_memalloc(content_size);
		content_copy = ft_memcpy(content_copy, content, content_size);
		res->content = content_copy;
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
