/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:41:14 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/18 16:03:27 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *p, int c, size_t n)
{
	size_t		i;
	t_byte		bc;
	t_byte		*bp;

	i = 0;
	bp = (t_byte*)p;
	bc = (t_byte)c;
	while (i < n)
	{
		if (bp[i] == bc)
			return (&bp[i]);
		i++;
	}
	return (0);
}
