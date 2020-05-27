/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:55:33 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/28 01:01:34 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == s2)
			return (0);
		else
			return (-1);
	}
	if (ft_strcmp(s1, s2) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
