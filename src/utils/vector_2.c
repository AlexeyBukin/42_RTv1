/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:53 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/03 04:59:04 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"



t_num			vec_dot_product(t_vec a, t_vec b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a.x + a.y + a.z);
}

t_num			vec_angle_cos(t_vec a, t_vec b)
{
	return (vec_dot_product(vec_normalize(a), vec_normalize(b)));
}

t_vec			vec_cross_product(t_vec a, t_vec b)
{
	t_vec	vp;

	vp.x = a.y * b.z - b.y * a.z;
	vp.y = a.z * b.x - b.z * a.x;
	vp.z = a.x * b.y - b.x * a.y;
	return (vp);
}

t_num			vec_len(t_vec a)
{
	return (vec_dist(vec_zero(), a));
}

t_vec			vec_normalize(t_vec vec)
{
	t_num		len;

	len = vec_len(vec);
	if (len == 0)
		return (vec_inf());
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
