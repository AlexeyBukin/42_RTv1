/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_dot_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:09:43 by hush              #+#    #+#             */
/*   Updated: 2020/05/29 02:25:24 by hush             ###   ########.fr       */
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
**
** TODO edge grain bug fix
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
	a = vec_dot_product(ray.dir, ray.dir)
		- (1 + (d * d)) * num_sqr(vec_dot_product(ray.dir, v));
	b = (vec_dot_product(ray.dir, x) - vec_dot_product(ray.dir, v)
			* (1 + d * d) * vec_dot_product(x, v)) * 2;
	c = vec_dot_product(x, x) - (1 + d * d) * num_sqr(vec_dot_product(x, v));
	d = (b * b) - 4 * a * c;
	if (d < 0)
		return (vec_inf());
	d = sqrt(d);
	return ((t_vec){(-b - d) / (2 * a), (-b + d) / (2 * a), 0});
}

/*
** m = D|V*t + X|V
*/

static
t_vec 				cone_capped(t_ray ray, t_cone cone)
{
	t_num			maxm;
	t_vec			points;
	t_vec			v;
	t_vec			m;
	t_num			x_dot_v;

	v = vec_normalize(vec_minus(cone.cap, cone.pos));
	points = cone_intersect(ray, cone, v);
	maxm = vec_len(vec_minus(cone.pos, cone.cap));
	x_dot_v = vec_dot_product(vec_minus(ray.pos, cone.pos), v);
	m.x = vec_dot_product(ray.dir, vec_mult(v, points.x)) + x_dot_v;
	m.y = vec_dot_product(ray.dir, vec_mult(v, points.y)) + x_dot_v;
	if (m.x >= 0 && m.x <= maxm && m.y >= 0 && m.y <= maxm)
		return (points);
	if ((m.x < 0 && m.y < 0) || (m.x > maxm && m.y > maxm))
		return (vec_inf());
	if (m.x < 0)
		points.x = trace_dot_cap(ray, (t_ray) {cone.pos, vec_mult(v, -1)});
	if (m.y < 0)
		points.y = trace_dot_cap(ray, (t_ray) {cone.pos, vec_mult(v, -1)});
	if (m.x > maxm)
		points.x = trace_dot_cap(ray, (t_ray){cone.cap, v});
	if (m.y > maxm)
		points.y = trace_dot_cap(ray, (t_ray){cone.cap, v});
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