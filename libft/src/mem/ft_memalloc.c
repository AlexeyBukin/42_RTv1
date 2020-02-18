/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:12:10 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/18 16:03:27 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	t_byte		*tp;

	tp = (t_byte*)malloc(size);
	if (tp != 0)
	{
		tp = (t_byte*)ft_bzero(tp, size);
	}
	return (tp);
}
