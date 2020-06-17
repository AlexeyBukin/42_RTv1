/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:29:24 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 21:10:33 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec		vec_do_vec(t_vec v1, t_vec v2, t_num f(t_num n1, t_num n2))
{
	v1.x = f(v1.x, v2.x);
	v1.y = f(v1.y, v2.y);
	v1.z = f(v1.z, v2.z);
	return (v1);
}

t_vec		vec_do_num(t_vec v, t_num n, t_num f(t_num n1, t_num n2))
{
	v.x = f(v.x, n);
	v.y = f(v.y, n);
	v.z = f(v.z, n);
	return (v);
}

t_vec		vec_from_color(t_col c)
{
	return (vec_div_num(vec(c.r, c.g, c.b), 255.0));
}

char		*vec_to_str(t_vec a)
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

char		*vec_to_str_color(t_vec a)
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
