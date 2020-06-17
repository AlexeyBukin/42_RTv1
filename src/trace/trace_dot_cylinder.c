/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_dot_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:09:55 by hush              #+#    #+#             */
/*   Updated: 2020/06/17 23:44:31 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** http://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20
** raytracing%20shapes.htm
**
** a   = D|D - (D|V)^2
** b/2 = D|X - (D|V)*(X|V)
** c   = X|X - (X|V)^2 - r*r
*/

/*
** also used in trace_normal_cylinder.c
*/

t_vec				cylinder_intersect(t_ray ray, t_cylinder cyl, t_vec v)
{
	t_vec		x;
	t_num		a;
	t_num		b;
	t_num		c;
	t_num		d;

	x = vec_minus(ray.pos, cyl.pos);
	a = vec_dot(ray.dir, ray.dir)
			- num_sqr(vec_dot(ray.dir, v));
	b = (vec_dot(ray.dir, x) - vec_dot(ray.dir, v)
			* vec_dot(x, v)) * 2;
	c = vec_dot(x, x) - num_sqr(vec_dot(x, v))
			- num_sqr(cyl.r);
	d = (b * b) - 4 * a * c;
	if (d < 0)
		return (vec_inf());
	d = sqrt(d);
	return ((t_vec){(-b - d) / (2 * a), (-b + d) / (2 * a), 0});
}

/*
** m = D|V*t + X|V
*/

static t_vec		cylinder_capped(t_ray ray, t_cylinder cyl)
{
	t_num			maxm;
	t_vec			points;
	t_vec			v;
	t_vec			m;
	t_num			x_dot_v;

	v = vec_normalize(vec_minus(cyl.cap, cyl.pos));
	points = cylinder_intersect(ray, cyl, v);
	maxm = vec_len(vec_minus(cyl.pos, cyl.cap));
	x_dot_v = vec_dot(vec_minus(ray.pos, cyl.pos), v);
	m.x = vec_dot(ray.dir, vec_mult_num(v, points.x)) + x_dot_v;
	m.y = vec_dot(ray.dir, vec_mult_num(v, points.y)) + x_dot_v;
	if (m.x >= 0 && m.x <= maxm && m.y >= 0 && m.y <= maxm)
		return (points);
	if ((m.x < 0 && m.y < 0) || (m.x > maxm && m.y > maxm))
		return (vec_inf());
	if (m.x < 0)
		points.x = trace_dot_cap(ray, (t_ray) {cyl.pos, vec_invert(v)});
	if (m.y < 0)
		points.y = trace_dot_cap(ray, (t_ray) {cyl.pos, vec_invert(v)});
	if (m.x > maxm)
		points.x = trace_dot_cap(ray, (t_ray){cyl.cap, v});
	if (m.y > maxm)
		points.y = trace_dot_cap(ray, (t_ray){cyl.cap, v});
	return (points);
}

t_num				trace_dot_cylinder(t_ray ray, t_figure *fig)
{
	t_num			minimal;
	t_vec			points;

	if (fig == NULL)
		return (INFINITY);
	points = cylinder_capped(ray, fig->figs.cyl);
	minimal = INFINITY;
	if (points.x > 0 && points.x < minimal)
		minimal = points.x;
	if (points.y > 0 && points.y < minimal)
		minimal = points.y;
	return (minimal);
}
