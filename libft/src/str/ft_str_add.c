/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 00:19:16 by hush              #+#    #+#             */
/*   Updated: 2020/05/22 16:45:17 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_add(char *s1, const char *s2)
{
	char		*res;
	size_t		len;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		return (ft_strdup(s2));
	len = ft_strlen(s1);
	res = ft_realloc(s1, len, len + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	res = ft_strcat(res, s2);
	return (res);
}
