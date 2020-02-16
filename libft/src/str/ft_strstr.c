/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:05:16 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:16:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	t2_len;
	int		i;

	i = 0;
	if (s2[0] == '\0')
	{
		return ((char*)s1);
	}
	t2_len = ft_strlen(s2);
	while (s1[i] != '\0')
	{
		if (ft_strncmp(&s1[i], s2, t2_len) == 0)
		{
			return ((char*)&(s1[i]));
		}
		i++;
	}
	return (0);
}
