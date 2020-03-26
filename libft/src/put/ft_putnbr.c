/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:07:28 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	pow;
	long	abs_n;
	char	c;

	if (n == 0 && (c = '0') == '0')
	{
		write(1, &c, 1);
		return ;
	}
	pow = 100000000000;
	if ((abs_n = n) < 0)
	{
		c = '-';
		write(1, &c, 1);
		abs_n *= (-1);
	}
	while (abs_n / pow == 0)
		pow /= 10;
	while (pow > 0)
	{
		c = abs_n / pow + '0';
		write(1, &c, 1);
		abs_n %= pow;
		pow /= 10;
	}
}
