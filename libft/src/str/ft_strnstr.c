/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:49:14 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:16:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len2;
	size_t		i;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)&s1[i]);
	len2 = ft_strlen(s2);
	while (s1[i] != '\0' && n-- >= len2)
	{
		if (s1[i] == s2[0] && ft_memcmp(&s1[i], s2, len2) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (0);
}
