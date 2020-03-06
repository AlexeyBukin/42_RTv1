/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:34:55 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 03:10:01 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ldtoa_prec(long double num, int prec)
{
	int			i;
	char		*res;
	int			flags[FLAGS_LEN];
	char		sign;

	sign = 1;
	i = 0;
	while (i < FLAGS_LEN)
	{
		flags[i] = 0;
		i++;
	}
	if (prec < 0)
		prec = 6;
	flags[PRECISION] = prec;
	if ((flags[SPECIAL] = f_is_special(num)) < 0)
	{
		sign = -1;
		flags[SPECIAL] *= -1;
	}
	if (flags[SPECIAL] == F_N0_SPECIAL)
		res = bad_way(flags, num);
	else
		res = f_get_special(flags);
	return (width_format(flags, res, sign));
}
