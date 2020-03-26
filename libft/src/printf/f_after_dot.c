/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_after_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:50:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*after_prec_2(int *flags, char *a_dot, int b)
{
	if (flags == NULL || a_dot == NULL)
		return (NULL);
	while (a_dot[b] > '9')
	{
		a_dot[b] = '0';
		if (b > 0)
			a_dot[--b]++;
		else
		{
			flags[SPECIAL] = F_ROUND_YES;
			break ;
		}
	}
	b = 0;
	while (++b < flags[PRECISION])
		if (a_dot[b] > '9')
			a_dot[b] = '0';
	b = flags[PRECISION];
	if (b == 0)
		b = 3;
	a_dot[b] = '\0';
	return (a_dot);
}

char			*f_after_dot_prec(int *flags, long double num)
{
	int		len;
	int		b;
	int		i;
	char	*a_dot;

	a_dot = f_after_dot(num);
	len = (int)ft_strlen(a_dot);
	if (flags[PRECISION] >= len)
	{
		a_dot = ft_strjoin_free(a_dot,
				ft_str_spam("0", flags[PRECISION] - len + 3));
	}
	b = flags[PRECISION];
	if (a_dot[b] == '4' && len > flags[PRECISION] && (i = 1) == 1)
	{
		while (b + i < len && a_dot[b + i] == '9')
			i++;
		if (a_dot[b + i] >= '5' && a_dot[b + i] <= '9' && i > 8)
			a_dot[b - 1]++;
	}
	if (a_dot[b] >= '5' && len > flags[PRECISION] && b > 0)
		a_dot[b - 1]++;
	b = b - (b >= 1);
	flags[SPECIAL] = F_ROUND_NO;
	return (after_prec_2(flags, a_dot, b));
}

char			*f_after_dot(long double num)
{
	int		i;
	char	b;
	char	a[5000];

	ft_bzero(a, 5000);
	i = 0;
	if (num == 0)
		return (ft_strdup(""));
	while (num > 0 && i < 5000)
	{
		num = num * 10;
		b = (char)num;
		num -= b;
		a[i] = b + '0';
		i++;
	}
	return (ft_strdup(a));
}
