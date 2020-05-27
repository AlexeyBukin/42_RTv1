/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:34:55 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/28 01:01:34 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ldtoa_prec(long double num, int prec)
{
	char		*res;
	int			*flags;
	char		sign;

	sign = 1;
	if ((flags = (int*)ft_malloc(sizeof(int) * FLAGS_LEN)) == NULL)
		return (NULL);
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
	res = width_format(flags, res, sign);
	ft_free(flags);
	return (res);
}
