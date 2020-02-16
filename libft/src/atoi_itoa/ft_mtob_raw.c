/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtob_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 01:45:57 by kcharla           #+#    #+#             */
/*   Updated: 2020/01/23 01:45:58 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mtob_raw(void const *ptr, size_t bits)
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
	i = 0;
	while (i < bytes)
	{
		j = -1;
		while (++j < 8)
			if (((b[i] >> j) & 00000001) == 00000001)
				res[i * 8 + j] = '1';
		i++;
	}
	return (res);
}
