/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:30:54 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:16:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;

	n = size;
	i = 0;
	j = 0;
	while (n != 0 && d[i] != '\0')
	{
		n--;
		i++;
	}
	n = size - i;
	if (n == 0)
		return (i + ft_strlen(s));
	while (s[j] != '\0' && n != 1)
	{
		d[i + j] = s[j];
		j++;
		n--;
	}
	d[i + j] = '\0';
	return (i + ft_strlen(s));
}
