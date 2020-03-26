/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_o3(long long int d, int len, char *num, int *flags)
{
	if (flags[SHARP] == 1 && d != 0)
		num = ft_strjoin_free(ft_strdup("0"), num);
	if (flags[WIDTH] > 0 && (len = (int)ft_strlen(num)) < flags[WIDTH])
	{
		if (flags[MINUS] == 1)
			num = ft_strjoin_free(num, ft_str_spam(" ", flags[WIDTH] - len));
		else
			num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
	}
	return (num);
}

char	*ft_insert_o2(long long int d, int *flags)
{
	char	*num;
	int		len;

	if (flags[PRECISION] == -1 && d == 0 && flags[SHARP] == 0)
		num = ft_strdup("");
	else
		num = ft_ulltoa_base(d, BASE8);
	len = (int)ft_strlen(num);
	len = (flags[SHARP] == 1 && d != 0) ? len + 1 : len;
	if (flags[PRECISION] > len)
		num = ft_strjoin_free(ft_str_spam("0", flags[PRECISION] - len), num);
	if (flags[ZERO] == 1 && flags[PRECISION] == 0 && flags[MINUS] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1)
			len++;
		len = (flags[SHARP] == 1 && d != 0) ? len + 1 : len;
		if (len < flags[WIDTH])
			num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}
	return (ft_insert_o3(d, len, num, flags));
}

char	*ft_insert_o(va_list arg, int *flags)
{
	unsigned long long	d;

	if (flags[CAST] == CAST_NO)
		d = (unsigned int)va_arg(arg, int);
	else if (flags[CAST] == CAST_HH)
		d = (unsigned char)va_arg(arg, int);
	else if (flags[CAST] == CAST_H)
		d = (unsigned short)va_arg(arg, int);
	else if (flags[CAST] == CAST_L)
		d = (unsigned long)va_arg(arg, long int);
	else if (flags[CAST] == CAST_LL)
	{
		d = (unsigned long long)va_arg(arg, long long int);
	}
	else
		return (NULL);
	return (ft_insert_o2(d, flags));
}
