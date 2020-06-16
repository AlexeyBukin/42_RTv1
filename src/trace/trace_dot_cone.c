/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_dot_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:09:43 by hush              #+#    #+#             */
/*   Updated: 2020/06/16 13:19:18 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** http://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20
** raytracing%20shapes.htm
**
** a   = D|D - (1+k*k)*(D|V)^2
** b/2 = D|X - (1+k*k)*(D|V)*(X|V)
** c   = X|X - (1+k*k)*(X|V)^2
*/

t_vec 				cone_intersect(t_ray ray, t_cone cone, t_vec v)
{
	t_vec		x;
	t_num		a;
	t_num		b;
	t_num		c;
	t_num 		d;

	d = cone.r / vec_len(vec_minus(cone.pos, cone.cap));
	x = vec_minus(ray.pos, cone.pos);
	a = vec_dot(ray.dir, ray.dir)
		- (1 + (d * d)) * num_sqr(vec_dot(ray.dir, v));
	b = (vec_dot(ray.dir, x) -
		 vec_dot(ray.dir, v)
			* (1 + d * d) * vec_dot(x, v)) * 2;
	c = vec_dot(x, x) - (1 + d * d) * num_sqr(vec_dot(x, v));
	d = (b * b) - 4 * a * c;
	if (d < 0)
		return (vec_inf());
	d = sqrt(d);
	return (vec((-b - d) / (2 * a), (-b + d) / (2 * a), 0));
}

/*
** m = D|V*t + X|V
*/

#define CONE_EPSILON 0.001

static
t_vec 				cone_capped(t_ray ray_in, t_cone cone)
{
	t_num			maxm;
	t_vec			points;
	t_vec			v;
	t_vec			m;
	t_vec			clamped;
	t_num			x_dot_v;

	v = vec_normalize(vec_minus(cone.cap, cone.pos));
	ray_in.dir = vec_normalize(ray_in.dir);
	points = cone_intersect(ray_in, cone, v);
	maxm = vec_len(vec_minus(cone.pos, cone.cap));
	x_dot_v = vec_dot(vec_minus(ray_in.pos, cone.pos), v);
	m.x = vec_dot(ray_in.dir, vec_mult_num(v, points.x)) + x_dot_v;
	m.y = vec_dot(ray_in.dir, vec_mult_num(v, points.y)) + x_dot_v;

	clamped.x = num_clamp(m.x, 0, maxm);
	clamped.y = num_clamp(m.y, 0, maxm);

//	if (clamped.x == m.x && clamped.y == m.y)
//		return (points);

	if (clamped.x != m.x && clamped.y != m.y)
		return (vec_inf());
	if (clamped.x != m.x)
		points.x = trace_dot_cap(ray_in, ray(cone.cap, v));
	if (clamped.y != m.y)
		points.y = trace_dot_cap(ray_in, ray(cone.cap, v));

//
//	if (m.x > 0 && m.x < maxm && m.y > 0 && m.y <= maxm)
//		return (points);
//	//if ((m.x < 0 && m.y < 0) || (m.x > maxm && m.y > maxm))
//	if (m.x != num_clamp(m.x, 0, maxm) && m.y != num_clamp(m.y, 0, maxm))
//		return (vec_inf());
//	if (m.x < 0)
//		points.x = trace_dot_cap(ray_in, (t_ray) {cone.pos, vec_invert(v)});
//	if (m.y < 0)
//		points.y = trace_dot_cap(ray_in, (t_ray) {cone.pos, vec_invert(v)});
//	if (m.x > maxm)
//		points.x = trace_dot_cap(ray_in, (t_ray){cone.cap, v});
//	if (m.y > maxm)
//		points.y = trace_dot_cap(ray_in, (t_ray){cone.cap, v});
	return (points);
}

t_num				trace_dot_cone(t_ray ray, t_figure *fig)
{
	t_num			minimal;
	t_vec			points;

	if (fig == NULL)
		return (INFINITY);
	points = cone_capped(ray, fig->cone);
	minimal = INFINITY;
	if (points.x > 0 && points.x < minimal)
		minimal = points.x;
	if (points.y > 0 && points.y < minimal)
		minimal = points.y;
	return (minimal);
}