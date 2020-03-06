/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double3_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:35 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 03:10:00 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char		*d3_to_str(t_double3 a)
{
	char		*res;

	res = ft_strjoin_free(ft_strdup("("), ft_ldtoa(a.x));
	res = ft_strjoin_free(res, ft_strdup(" | "));
	res = ft_strjoin_free(res, ft_ldtoa(a.y));
	res = ft_strjoin_free(res, ft_strdup(" | "));
	res = ft_strjoin_free(res, ft_ldtoa(a.z));
	res = ft_strjoin_free(res, ft_strdup(")"));
	return (res);
}

char		*d3_to_str_color(t_double3 a)
{
	char		*res;

	res = ft_strjoin_free(ft_strdup("(\033[0;31m"), ft_ldtoa(a.x));
	res = ft_strjoin_free(res, ft_strdup("\033[0m | \033[0;32m"));
	res = ft_strjoin_free(res, ft_ldtoa(a.y));
	res = ft_strjoin_free(res, ft_strdup("\033[0m | \033[0;34m"));
	res = ft_strjoin_free(res, ft_ldtoa(a.z));
	res = ft_strjoin_free(res, ft_strdup("\033[0m)"));
	return (res);
}
