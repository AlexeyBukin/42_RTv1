/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_way_before.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:37:36 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*multiply_by_two(char *res)
{
	int tmp;
	int i;

	if (res == NULL)
		return (NULL);
	tmp = 0;
	i = 0;
	while (res[i] != 0)
	{
		tmp = tmp + (res[i] - '0') * 2;
		res[i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (tmp != 0)
		res[i] = (tmp % 10) + '0';
	return (res);
}

char				*add_to(char *res, char *additive)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (additive[i] != 0)
	{
		tmp = tmp + '0' * (res[i] < '0' || res[i] > '9') +
				(res[i] - '0') + (additive[i] - '0');
		res[i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (tmp != 0)
		res[i] = (tmp % 10) + '0';
	return (res);
}

char				*ft_before_dot_raw(char *pointer, size_t count)
{
	char				*res;
	char				*add;
	int					i;
	int					j;

	if (pointer == NULL)
		return (NULL);
	res = ft_strnew(count * 3);
	res[0] = '0';
	add = ft_strnew(count * 3);
	add[0] = '1';
	i = -1;
	while (++i < (int)count)
	{
		j = -1;
		while (++j < 8)
		{
			if (((pointer[i] >> j) & 00000001) == 00000001)
				add_to(res, add);
			multiply_by_two(add);
		}
	}
	free(add);
	return (res);
}

char				*ft_before_dot_big(int exp, t_ldouble_10_u parser)
{
	char				*result;
	char				*before_dot_bits;
	unsigned char		last_bit;
	unsigned long long	mcopy;

	last_bit = (parser.bytes.byte0) << (exp % 8);
	mcopy = (parser.parts.mantissa >> (8 - (exp % 8)));
	if ((before_dot_bits = ft_strnew(exp / 8 + 1)) == NULL)
		return (NULL);
	ft_memset(before_dot_bits, 0, exp / 8 + 1);
	ft_memcpy(&(before_dot_bits[(exp - 64) / 8 + 1]), &mcopy, 8);
	ft_memcpy(&(before_dot_bits[(exp - 64) / 8]), &last_bit, 1);
	result = ft_strrev(ft_before_dot_raw(before_dot_bits, exp / 8 + 1));
	free(before_dot_bits);
	return (result);
}

char				*ft_before_dot(int *flags, long double num)
{
	t_ldouble_10_u			parser;
	unsigned long long		mcopy;
	int						exp;
	char					*result;

	parser.num = num;
	exp = 1 + parser.parts.exponent - 16383;
	(void)flags;
	if (exp > 0)
	{
		if (exp < 64)
		{
			mcopy = (parser.parts.mantissa >> (64 - exp));
			result = ft_strrev(ft_before_dot_raw((char *)&mcopy, exp / 8 + 1));
		}
		else
		{
			result = ft_before_dot_big(exp, parser);
		}
	}
	else
		result = ft_strdup("0");
	return (result);
}
