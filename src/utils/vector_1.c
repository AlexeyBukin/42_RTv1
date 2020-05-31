/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:37:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/03 06:14:30 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	vec_plus(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec	vec_minus(t_vec a, t_vec b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec	vec_mult(t_vec a, t_num b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}

t_num		vec_dist_sqr(t_vec a, t_vec b)
{
	t_num		dist_sqr;

	dist_sqr = (a.x - b.x) * (a.x - b.x);
	dist_sqr += (a.y - b.y) * (a.y - b.y);
	dist_sqr += (a.z - b.z) * (a.z - b.z);
	return (dist_sqr);
}

t_num		vec_dist(t_vec a, t_vec b)
{
	if (vec_isinf (a) || vec_isinf (b))
		return (INFINITY);
	return (sqrt(vec_dist_sqr(a, b)));
}
