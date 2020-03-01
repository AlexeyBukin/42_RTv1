/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:30:39 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/01 14:32:49 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_puterr_null(int error_code, char *err_msg)
{
	ft_putstr("Error occured! (error code: ");
	ft_putnbr(error_code);
	ft_putstr(" )\n");
	if (err_msg != NULL)
	{
		ft_putstr("Error message: \'");
		ft_putstr(err_msg);
		ft_putstr("\'\n");
	}
	return (NULL);
}
