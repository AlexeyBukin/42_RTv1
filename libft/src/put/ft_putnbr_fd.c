/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:31:23 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:16:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	pow;
	long	abs_n;
	char	c;

	if (n == 0 && (c = '0') == '0')
	{
		write(fd, &c, 1);
		return ;
	}
	pow = 100000000000;
	if ((abs_n = n) < 0)
	{
		c = '-';
		write(fd, &c, 1);
		abs_n *= (-1);
	}
	while (abs_n / pow == 0)
		pow /= 10;
	while (pow > 0)
	{
		c = abs_n / pow + '0';
		write(fd, &c, 1);
		abs_n %= pow;
		pow /= 10;
	}
}
