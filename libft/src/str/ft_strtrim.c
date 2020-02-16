/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:38:48 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:16:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	int		i;
	int		j;

	if (s == 0)
		return (0);
	i = 0;
	while (ft_is_blank(s[i]))
	{
		i++;
	}
	j = i;
	while (s[j] != '\0')
	{
		j++;
	}
	j--;
	while (ft_is_blank(s[j]))
	{
		j--;
	}
	if (j < i)
		return (ft_strnew(0));
	return (ft_strsub(s, i, j - i + 1));
}
