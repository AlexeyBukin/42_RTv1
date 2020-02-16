/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:21:46 by lmelina           #+#    #+#             */
/*   Updated: 2020/01/31 15:29:09 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** TODO view this
*/

char	*insert_from_to2(char *res, char *input, size_t to, int i)
{
	while (input[to] != '\0')
	{
		res[i] = input[to];
		i++;
		to++;
	}
	res[i] = '\0';
	return (res);
}

char	*insert_from_to(char *input, char *insertion, size_t from, size_t to)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*res;

	len1 = ft_strlen(input) - (to - from + 1);
	len2 = ft_strlen(insertion);
	i = 0;
	j = 0;
	if (!(res = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (i < from)
	{
		res[i] = input[i];
		i++;
	}
	while (j < len2)
	{
		res[i] = insertion[j];
		i++;
		j++;
	}
	res = insert_from_to2(res, input, ++to, i);
	return (res);
}
