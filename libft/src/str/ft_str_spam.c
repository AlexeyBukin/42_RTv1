/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_spam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:14:37 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_spam(const char *s, int repetitions)
{
	int		i;
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = (char*)malloc(sizeof(char) * (len * repetitions + 1));
	if (res != NULL)
	{
		i = 0;
		while (i < (int)(len * repetitions))
		{
			res[i] = s[i % len];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
