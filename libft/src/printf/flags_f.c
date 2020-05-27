/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:40:37 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/28 01:03:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*worst_way(int *flags, long double num)
{
	char				*bdot_a;
	char				*after_dot;

	if ((bdot_a = ft_before_dot(flags, num)) == NULL)
		return (NULL);
	if (flags[PRECISION] != 0 || flags[SHARP] == 1)
	{
		if ((bdot_a = ft_strjoin_free(bdot_a, ft_strdup("."))) == NULL)
			return (NULL);
	}
	if (flags[PRECISION] != 0)
	{
		if ((after_dot = f_after_dot_prec(flags, 0)) == NULL)
			return (NULL);
		bdot_a = ft_strjoin_free(bdot_a, after_dot);
	}
	return (bdot_a);
}

char		*no_way(int *flags, unsigned long long bdot, char *after_dot)
{
	char *bdot_a;

	if (flags[PRECISION] == 0)
	{
		if (after_dot[0] == '5')
		{
			if ((bdot % 2) == 1 || ft_strlen(after_dot) > 1)
				bdot++;
		}
		else if (after_dot[0] > '5' && after_dot[0] <= '9')
			bdot++;
	}
	else if (flags[SPECIAL] == F_ROUND_YES)
		bdot++;
	if ((bdot_a = ft_ulltoa(bdot)) == NULL)
		return (NULL);
	if (flags[PRECISION] != 0 || flags[SHARP] == 1)
		bdot_a = ft_strjoin_free(bdot_a, ft_strdup("."));
	if (flags[PRECISION] != 0)
		bdot_a = ft_strjoin_free(bdot_a, after_dot);
	else
		free(after_dot);
	return (bdot_a);
}

char		*bad_way(int *flags, long double num)
{
	char				*after_dot;
	unsigned long long	bdot;

	if (flags == NULL)
		return (NULL);
	num *= (num < 0) ? -1 : 1;
	if (num > (long double)1000000L * 1000000L * 1000000L)
		return (worst_way(flags, num));
	bdot = (long long int)num;
	if ((after_dot = f_after_dot_prec(flags, num - bdot)) == NULL)
		return (NULL);
	return (no_way(flags, bdot, after_dot));
}

char		*ft_float(va_list arg, int *flags)
{
	char			sign;
	char			*res;
	long double		num;

	if (flags == NULL)
		return (NULL);
	if (flags[CAST] == CAST_BIG_L)
		num = (long double)va_arg(arg, long double);
	else
		num = (long double)va_arg(arg, double);
	if (flags[PRECISION] == 0)
		flags[PRECISION] = 6;
	if (flags[PRECISION] == -1)
		flags[PRECISION] = 0;
	sign = 1;
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
