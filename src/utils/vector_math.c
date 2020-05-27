/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:53 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec			vec(double x, double y, double z)
{
	t_vec   vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double			vec_dot_product(t_double3 a, t_double3 b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a.x + a.y + a.z);
}

double			vec_angle_cos(t_vec a, t_vec b)
{
	return (vec_dot_product(vec_normalize(a), vec_normalize(b)));
}

t_double3		vec_cross_product(t_double3 a, t_double3 b)
{
	t_double3	vp;

	vp.x = a.y * b.z - b.y * a.z;
	vp.y = a.z * b.x - b.z * a.x;
	vp.z = a.x * b.y - b.x * a.y;
	return (vp);
}

double			vec_len(t_double3 a)
{
	t_double3	zero;

	zero = (t_double3){0, 0, 0};
	return (ft_absd(d3_dist(zero, a)));
}

t_double3		vec_normalize(t_double3 vec)
{
	double		len;

	len = vec_len(vec);
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
