/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_special.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:50:22 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/28 01:01:34 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** double treated as 10-bytes
*/

int			f_is_special(long double num)
{
	char				sign;
	unsigned char		bytes[10];
	unsigned char		res;

	res = 0;
	while (res < 10)
		bytes[res++] = 0;
	ft_memcpy(bytes, &num, 10);
	sign = ((bytes[9] & (unsigned char)0x80) == 0x00) ? 1 : -1;
	if ((bytes[9] | 0x80) == 0xff && (bytes[8] == 0xff))
	{
		res = bytes[7] | (unsigned char)0x3f;
		if (res == 0xff || res == 0x7f)
			return (F_NAN);
		else
		{
			res = (bytes[7] & (unsigned char)0x3f) + bytes[6] + bytes[5];
			res += bytes[4] + bytes[3] + bytes[2] + bytes[1] + bytes[0];
			if (res == 0x00)
				return (F_INF * sign);
			else
				return (F_NAN);
		}
	}
	return (F_N0_SPECIAL * sign);
}

char		*f_get_special(int *flags)
{
	char				*res;

	if (flags == NULL)
		return (NULL);
	flags[ZERO] = 0;
	if (flags[SPECIAL] == F_NAN)
	{
		flags[PLUS] = 0;
		flags[SPACE] = 0;
		res = ft_strdup("nan");
	}
	else if (flags[SPECIAL] == F_INF)
	{
		res = ft_strdup("inf");
	}
	else
		return (NULL);
	if (flags[FLAG] == 'F')
	{
		ft_str_up(res);
	}
	return (res);
}
