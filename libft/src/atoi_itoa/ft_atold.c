/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:24:06 by hush              #+#    #+#             */
/*   Updated: 2020/03/26 17:24:28 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double			ft_atold(const char *str)
{
	size_t			i;
	long double		res;
	long double		negative;

	negative = 1;
	res = 0;
	i = 0;
	while (ft_is_blank(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	res *= negative;
	if (str[i] == '.')
		while (str[i] >= '0' && str[i] <= '9')
		{
			negative /= 10;
			res += negative * (str[i] - 48);
			i++;
		}
	return (res);
}
