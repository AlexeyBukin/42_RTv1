/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:08 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	res = (char*)ft_memcpy(res, s + start, len);
	res[len] = '\0';
	free(s);
	return (res);
}
