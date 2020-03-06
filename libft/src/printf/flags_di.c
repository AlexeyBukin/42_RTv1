/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2020/03/06 03:10:01 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_d3(long long int d, int len, char *num, int *flags)
{
	if (d < 0)
		num = ft_strjoin_free(ft_strdup("-"), num);
	if (flags[PLUS] == 1 && d >= 0)
		num = ft_strjoin_free(ft_strdup("+"), num);
	if (flags[SPACE] == 1 && flags[PLUS] == 0 && d >= 0)
		num = ft_strjoin_free(ft_strdup(" "), num);
	if (flags[WIDTH] > 0 && (int)ft_strlen(num) < flags[WIDTH])
	{
		len = (int)ft_strlen(num);
		if (flags[MINUS] == 0)
			num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
		else
			num = ft_strjoin_free(num, ft_str_spam(" ", flags[WIDTH] - len));
	}
	return (num);
}

char	*ft_insert_d2(long long int d, int *flags)
{
	char			*num;
	int				len;

	if (flags[PRECISION] == PREC_INTENDED_ZERO && d == 0)
		num = ft_strdup("");
	else
		num = ft_ulltoa(ft_absl(d));
	len = (int)ft_strlen(num);
	if (flags[PRECISION] > len)
		num = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - len), num);
	if (flags[ZERO] == 1 && flags[PRECISION] == 0 && flags[MINUS] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1 || d < 0)
			len++;
		if (flags[WIDTH] > len)
			num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}
	return (ft_insert_d3(d, len, num, flags));
}

char	*ft_insert_d(va_list arg, int *flags)
{
	long long int	d;

	if (flags[CAST] == CAST_NO)
		d = va_arg(arg, int);
	else if (flags[CAST] == CAST_HH)
		d = (char)va_arg(arg, int);
	else if (flags[CAST] == CAST_H)
		d = (short)va_arg(arg, int);
	else if (flags[CAST] == CAST_L)
		d = va_arg(arg, long int);
	else if (flags[CAST] == CAST_LL)
	{
		d = va_arg(arg, long long int);
	}
	else
		return (NULL);
	return (ft_insert_d2(d, flags));
}
