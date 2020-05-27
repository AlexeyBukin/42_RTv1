/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:16:43 by hush              #+#    #+#             */
/*   Updated: 2020/05/04 15:33:25 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			ft_atof(const char *str)
{
	size_t	i;
	float	res;
	float	negative;

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
		res = (float) (res * 10 + (str[i++] - 48.0));
	res *= negative;
	if (str[i] == '.')
		while (str[i] >= '0' && str[i] <= '9')
		{
			negative /= 10;
			res += (float) (negative * (str[i] - 48.0));
			i++;
		}
	return (res);
}
