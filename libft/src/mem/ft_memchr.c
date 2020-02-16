/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:41:14 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:16:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *p, int c, size_t n)
{
	size_t		i;
	uint8_t		bc;
	uint8_t		*bp;

	i = 0;
	bp = (uint8_t*)p;
	bc = (uint8_t)c;
	while (i < n)
	{
		if (bp[i] == bc)
			return (&bp[i]);
		i++;
	}
	return (0);
}
