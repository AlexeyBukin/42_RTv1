/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:23:19 by kcharla           #+#    #+#             */
/*   Updated: 2020/01/23 01:44:33 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mtob(void const *ptr, size_t bits)
{
	unsigned char	*b;
	int				i;
	int				j;
	int				bytes;
	char			*res;

	bytes = bits;
	bits = bytes * 8;
	b = (unsigned char*)ptr;
	res = (char*)malloc(sizeof(char) * (bits + 1));
	if (b == NULL || res == NULL)
		return (NULL);
	ft_memset(res, '0', bits);
	res[bits] = '\0';
	i = bytes;
	while (--i >= 0)
	{
		j = -1;
		while (++j < 8)
			if (((b[i] >> j) & 00000001) == 00000001)
				res[bits - i * 8 - j - 1] = '1';
	}
	return (res);
}
