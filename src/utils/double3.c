/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:37:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_double3	d3_plus(t_double3 a, t_double3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_double3	d3_minus(t_double3 a, t_double3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_double3	d3_mult(t_double3 a, double b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}

t_dot	dot(double x, double y, double z)
{
    t_dot   dot;

    dot.x = x;
    dot.y = y;
    dot.z = z;
    return (dot);
}

double		d3_dist_sqr(t_double3 a, t_double3 b)
{
	double		dist_sqr;

	dist_sqr = (a.x - b.x) * (a.x - b.x);
	dist_sqr += (a.y - b.y) * (a.y - b.y);
	dist_sqr += (a.z - b.z) * (a.z - b.z);
	return (dist_sqr);
}

double		d3_dist(t_double3 a, t_double3 b)
{
	if (d3_is_inf (a) || d3_is_inf (b))
		return (get_inf ());
	return (sqrt(d3_dist_sqr(a, b)));
}
