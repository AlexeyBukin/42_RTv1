/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:14:34 by kcharla           #+#    #+#             */
/*   Updated: 2020/01/31 12:14:52 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		bits_rev(unsigned char input)
{
	unsigned char	res;
	int				j;

	res = 0;
	j = 0;
	while (j < 8)
	{
		res = res | (((input >> j) & 00000001) << (7 - j));
		j++;
	}
	return (res);
}

void				*ft_mem_rev(void *pointer_v, size_t count)
{
	unsigned char	*pointer;
	unsigned char	tmp;
	size_t			i;

	pointer = (unsigned char *)pointer_v;
	i = 0;
	count--;
	while (i < count / 2 + (count % 2 == 1))
	{
		tmp = pointer[i];
		pointer[i] = bits_rev(pointer[count - i]);
		pointer[count - i] = bits_rev(tmp);
		i++;
	}
	if (count % 2 == 0)
	{
		pointer[count / 2] = bits_rev(pointer[count / 2]);
	}
	return (pointer);
}
