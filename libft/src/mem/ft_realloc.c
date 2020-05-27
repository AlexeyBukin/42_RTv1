/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 00:12:57 by hush              #+#    #+#             */
/*   Updated: 2020/05/23 19:25:27 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	return ft_memalloc(size);
}

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = ft_memalloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (old_ptr == NULL || old_size == 0)
		return (new_ptr);
	ft_memcpy(new_ptr, old_ptr, old_size);
	ft_free(old_ptr);
	return (new_ptr);
}

void	*ft_realloc_arr(void *ptr, size_t old, size_t new, size_t elem_size)
{
	return (ft_realloc(ptr, old * elem_size, new * elem_size));
}
