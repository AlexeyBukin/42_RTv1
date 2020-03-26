/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:20:24 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *buf, size_t len)
{
	size_t		i;
	t_byte		*pointer;

	i = 0;
	pointer = (t_byte*)buf;
	while (i < len)
	{
		pointer[i] = 0;
		i++;
	}
	return (buf);
}
