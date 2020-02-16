/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:37:42 by kcharla           #+#    #+#             */
/*   Updated: 2019/12/16 17:45:05 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*do_if_ok(uint8_t len, int n)
{
	char	sign;
	char	*res;

	while (n / power_ten(len) / 10 != 0)
		len++;
	sign = n < 0 ? -1 : 1;
	len = len + (sign == -1 ? 1 : 0) + 1;
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[len] = '\0';
	while (n != 0)
	{
		res[len - 1] = n % 10 * (sign == -1 ? -1 : 1) + '0';
		n = n / 10;
		len--;
	}
	res[0] = sign == -1 ? '-' : res[0];
	return (res);
}

char			*ft_itoa(int n)
{
	uint8_t	len;
	char	*res;

	if (n != 0)
	{
		len = 0;
		res = do_if_ok(len, n);
	}
	else
	{
		res = (char*)malloc(sizeof(char) * 2);
		if (res == 0)
			return (0);
		res[0] = '0';
		res[1] = '\0';
	}
	return (res);
}
