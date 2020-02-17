/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:24:28 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:16:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t count)
{
	size_t		i;
	t_byte		*tp;
	t_byte		*tps;

	tp = (t_byte*)dest;
	tps = (t_byte*)source;
	if (tp < tps)
	{
		i = 0;
		while (i < count)
		{
			tp[i] = tps[i];
			i++;
		}
	}
	else if (tp > tps)
	{
		i = count;
		while (i > 0)
		{
			tp[i - 1] = tps[i - 1];
			i--;
		}
	}
	return (dest);
}
