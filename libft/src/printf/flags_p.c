/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:23:35 by lmelina           #+#    #+#             */
/*   Updated: 2020/01/31 17:22:54 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_p2(char *num, int *flags)
{
	int		len;

	if (flags[ZERO] == 1 && flags[PRECISION] == 0)
	{
		len = (int)ft_strlen(num);
		if (flags[PLUS] == 1 || flags[SPACE] == 1)
			len++;
		if (len < flags[WIDTH])
			num = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), num);
	}
	if (flags[WIDTH] > 0 && (len = (int)ft_strlen(num)) < flags[WIDTH])
	{
		if (flags[MINUS] == 1)
			num = ft_strjoin_free(num, ft_str_spam(" ", flags[WIDTH] - len));
		else
			num = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), num);
	}
	return (num);
}

char	*ft_insert_p(va_list arg, int *flags)
{
	unsigned long long	d;
	char				*num;
	char				*zero;
	int					len;

	d = (unsigned long long)va_arg(arg, long long int);
	zero = ft_strdup("0x");
	if (flags[PRECISION] == -1 && d == 0)
		num = ft_strdup("");
	else
		num = ft_ulltoa_base(d, BASE16L);
	len = (int)ft_strlen(num);
	if (flags[PRECISION] > len)
		num = ft_strjoin_free(ft_str_spam(
				"0", flags[PRECISION] - ft_strlen(num)), num);
	num = ft_strjoin_free(zero, num);
	return (ft_insert_p2(num, flags));
}
