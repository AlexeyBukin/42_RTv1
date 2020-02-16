/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:20:24 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:11:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *buf, size_t len)
{
	size_t		i;
	uint8_t		*pointer;

	i = 0;
	pointer = (uint8_t*)buf;
	while (i < len)
	{
		pointer[i] = 0;
		i++;
	}
	return (buf);
}
