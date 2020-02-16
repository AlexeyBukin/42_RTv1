/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_div_by_ins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:06:47 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/26 20:36:34 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_str_div_by_ins(char const *str, int div, char const *ins)
{
	char	*res;
	char	**divided;
	int		i;

	if (str == NULL || ins == NULL || div < 1)
		return (NULL);
	divided = ft_str_div_by(str, div);
	if (divided == NULL)
		return (NULL);
	i = 0;
	while (divided[i] != 0)
		i++;
	i = ft_strlen(str) + ft_strlen(ins) * (i - 1);
	if ((res = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	res[0] = '\0';
	res = ft_strcat(res, divided[0]);
	i = 0;
	while (divided[++i] != 0)
	{
		res = ft_strcat(res, ins);
		res = ft_strcat(res, divided[i]);
	}
	ft_free_char_2d_arr(&divided);
	return (res);
}
