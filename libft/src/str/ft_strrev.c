/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 06:24:35 by kcharla           #+#    #+#             */
/*   Updated: 2020/01/31 11:19:45 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *res)
{
	size_t	i;
	size_t	len;
	char	tmp;

	len = ft_strlen(res);
	i = 0;
	while (i < len / 2)
	{
		tmp = res[i];
		res[i] = res[len - 1 - i];
		res[len - 1 - i] = tmp;
		i++;
	}
	return (res);
}
