/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_way_after.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:37:32 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 03:10:01 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_to_div(char *res, char *additive)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (additive[i] != 0)
		i++;
	i--;
	while (i >= 0)
	{
		tmp = tmp + '0' * (res[i] < '0' || res[i] > '9') +
				(res[i] - '0') + (additive[i] - '0');
		res[i] = (tmp % 10) + '0';
		tmp /= 10;
		i--;
	}
	return (res);
}

char	*divide_by_two(char *res)
{
	int tmp;
	int i;

	if (res == NULL)
		return (NULL);
	tmp = 0;
	i = 0;
	while (res[i] != 0)
	{
		tmp = tmp + (res[i] - '0');
		res[i] = (tmp / 2) + '0';
		tmp = (tmp % 2) * 10;
		i++;
	}
	if (tmp != 0)
		res[i] = (tmp / 2) + '0';
	return (res);
}

char	*ft_after_dot_raw(char *pointer, size_t count)
{
	char	*res;
	char	*add;
	int		i;
	int		j;

	if (pointer == NULL)
		return (NULL);
	res = ft_str_spam("0", count * 8);
	res[0] = '0';
	add = ft_str_spam("0", count * 8);
	add[0] = '5';
	i = -1;
	while (++i < (int)count)
	{
		j = -1;
		while (++j < 8)
		{
			if (((pointer[i] >> j) & 00000001) == 00000001)
				add_to_div(res, add);
			divide_by_two(add);
		}
	}
	free(add);
	return (res);
}

char	*ft_after_dot_big(int exp, t_ldouble_10_u parser)
{
	char				*result;
	char				*after_dot_bits;
	unsigned long long	mcopy;
	unsigned char		first_bit;

	first_bit = (parser.bytes.byte7);
	first_bit = first_bit >> ((-exp) % 8);
	mcopy = (parser.parts.mantissa);
	mcopy = mcopy << (8 - (-exp) % 8);
	after_dot_bits = ft_strnew((-exp) / 8 + 9);
	ft_memcpy(&(after_dot_bits[0]), &mcopy, 8);
	ft_memcpy(&(after_dot_bits[8]), &first_bit, 1);
	ft_mem_rev(after_dot_bits, (-exp) / 8 + 9);
	result = ft_after_dot_raw(after_dot_bits, ((-exp) / 8 + 9));
	free(after_dot_bits);
	return (result);
}

char	*ft_after_dot(long double num)
{
	t_ldouble_10_u			parser;
	int						exp;
	unsigned long long		mcopy;
	char					*ad_toa;

	parser.num = num;
	exp = 1 + parser.parts.exponent - 16383;
	if (exp > 64)
	{
		ad_toa = ft_strdup("000000");
	}
	else if (exp >= 0)
	{
		mcopy = (parser.parts.mantissa << exp);
		ft_mem_rev(&mcopy, 8);
		ad_toa = ft_after_dot_raw((char*)&mcopy, 8);
	}
	else
	{
		ad_toa = ft_after_dot_big(exp, parser);
	}
	return (ad_toa);
}
