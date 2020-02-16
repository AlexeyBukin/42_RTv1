/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_div_by.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:06:07 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/26 20:33:28 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_str_div_by(char const *str, int divisor)
{
	size_t	len;
	char	**res;
	int		str_count;
	int		i;

	if (str == NULL || divisor < 1)
		return (NULL);
	len = ft_strlen(str);
	str_count = len / divisor + (len % divisor == 0 ? 0 : 1);
	if ((res = (char**)malloc(sizeof(char*) * (str_count + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < str_count)
	{
		if ((i + 1) * divisor < (int)len)
			res[i] = ft_strsub(str, i * divisor, divisor);
		else
			res[i] = ft_strsub(str, i * divisor, (int)len - i * divisor);
		(res[i] == NULL) ? ft_free_char_2d_arr(&res) : 777;
	}
	res[str_count] = NULL;
	return (res);
}
