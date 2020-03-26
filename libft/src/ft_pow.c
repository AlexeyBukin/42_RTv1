/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:51:28 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int num, int pow)
{
	int		res;
	int		cpow;

	res = num;
	if (pow <= 0)
		return (1);
	cpow = 1;
	while (cpow < pow / 2)
	{
		res *= res;
		cpow *= 2;
	}
	while (cpow < pow)
	{
		res *= num;
		cpow++;
	}
	return (res);
}
