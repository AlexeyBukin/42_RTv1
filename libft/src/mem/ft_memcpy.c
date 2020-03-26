/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:27:03 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	size_t		i;
	t_byte		*tp;
	t_byte		*tps;

	i = 0;
	tp = (t_byte*)dest;
	tps = (t_byte*)source;
	if (tp == NULL && tps == NULL)
	{
		return (NULL);
	}
	while (i < count)
	{
		tp[i] = tps[i];
		i++;
	}
	return (dest);
}
