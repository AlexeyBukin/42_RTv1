/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 11:48:52 by hush              #+#    #+#             */
/*   Updated: 2020/05/29 13:46:38 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			vec_cmp_len(t_vec a, t_vec b)
{
	return (num_cmp(vec_dist_sqr(vec_zero(), a), vec_dist_sqr(vec_zero(), b)));
}

t_vec		vec_zero()
{
	return ((t_vec){0, 0, 0});
}

t_bool		vec_is_zero(t_vec a)
{
	return (a.x == 0 && a.y == 0 && a.z == 0);
}

t_bool		vec_point_is_behind(t_vec vec_from_zero, t_vec point)
{
	if (vec_from_zero.x * point.x + vec_from_zero.y * point.y
		+ vec_from_zero.z * point.z < 0)
		return (TRUE);
	return (FALSE);
}

t_vec		vec_invert(t_vec vector)
{
	return (vec_mult_num(vector, -1));
}