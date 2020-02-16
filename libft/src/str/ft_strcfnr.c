/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_strcfnr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:50:46 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:16:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcfnr(const char *s, int find, int replace)
{
	char	*res;

	if (s == 0)
		return (0);
	res = ft_strdup(s);
	res = (char*)ft_strfnr(res, find, replace);
	return (res);
}
