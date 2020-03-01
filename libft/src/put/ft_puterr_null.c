/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:07:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 21:19:59 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puterror(int error_code, char *err_msg)
{
	ft_putstr("Error occured! (error code: ");
	ft_putnbr(error_code);
	ft_putstr(" )\n");
	if (err_msg == 0)
	{
		ft_putstr("Error message: \'");
		ft_putstr(err_msg);
		ft_putstr("\'\n");
	}
	return (-1 * error_code);
}
