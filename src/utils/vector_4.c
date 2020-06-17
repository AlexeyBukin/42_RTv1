/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 11:48:52 by hush              #+#    #+#             */
/*   Updated: 2020/06/17 21:35:20 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec		vec_invert(t_vec vector)
{
	return (vec_mult_num(vector, -1));
}

t_vec		vec_normalize(t_vec vec)
{
	return (vec_do_num(vec, vec_len(vec), num_div));
}

t_num		vec_dot(t_vec a, t_vec b)
{
	return (vec_sum(vec_mult(a, b)));
}

t_vec		vec_cross(t_vec a, t_vec b)
{
	t_vec	vp;

	vp.x = a.y * b.z - b.y * a.z;
	vp.y = a.z * b.x - b.z * a.x;
	vp.z = a.x * b.y - b.x * a.y;
	return (vp);
}

t_num		vec_angle_cos(t_vec a, t_vec b)
{
	return (vec_dot(vec_normalize(a), vec_normalize(b)));
}
