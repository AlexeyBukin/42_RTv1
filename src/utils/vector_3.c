/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:35 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/02 01:45:17 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec			vec(t_num x, t_num y, t_num z)
{
	return ((t_vec){x, y, z});
}

char			*vec_to_str(t_vec a)
{
	char		*res;

	res = ft_strjoin_free(ft_strdup("<x:"), ft_ldtoa(a.x));
	res = ft_strjoin_free(res, ft_strdup(", y:"));
	res = ft_strjoin_free(res, ft_ldtoa(a.y));
	res = ft_strjoin_free(res, ft_strdup(", z:"));
	res = ft_strjoin_free(res, ft_ldtoa(a.z));
	res = ft_strjoin_free(res, ft_strdup(">"));
	return (res);
}

char			*vec_to_str_color(t_vec a)
{
	char		*res;

	res = ft_strjoin_free(ft_strdup("<\033[0;31mx:"), ft_ldtoa(a.x));
	res = ft_str_add(res, "\033[0m,\033[0;32m y:");
	res = ft_strjoin_free(res, ft_ldtoa(a.y));
	res = ft_str_add(res, "\033[0m,\033[0;34m z:");
	res = ft_strjoin_free(res, ft_ldtoa(a.z));
	res = ft_str_add(res, "\033[0m>");
	return (res);
}

t_bool			vec_isinf(t_vec a)
{
	return (isinf(a.x) || isinf(a.y) || isinf(a.z));
}

t_vec			vec_inf()
{
	return ((t_vec){INFINITY, INFINITY, INFINITY});
}