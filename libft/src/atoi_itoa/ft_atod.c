/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:23:21 by hush              #+#    #+#             */
/*   Updated: 2020/03/26 17:23:54 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_atod(const char *str)
{
	size_t	i;
	double	res;
	double	negative;

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
