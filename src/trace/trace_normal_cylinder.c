/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_bounce_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:09:12 by hush              #+#    #+#             */
/*   Updated: 2020/05/29 13:39:05 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static
t_vec 				cylinder_side_nrm(t_vec p, t_vec c, t_vec v, t_num m)
{
	p = vec_minus(p, c);
	p = vec_minus(p, vec_mult(v, m));
	return (p);
}

static
t_vec 				cylinder_m(t_ray ray, t_vec v, t_vec cyl_pos, t_vec points)
{
	t_num			x_dot_v;
	t_vec			m;

	x_dot_v = vec_dot_product(vec_minus(ray.pos, cyl_pos), v);
	m.x = vec_dot_product(ray.dir, vec_mult(v, points.x)) + x_dot_v;
	m.y = vec_dot_product(ray.dir, vec_mult(v, points.y)) + x_dot_v;
	return (m);
}

t_vec				trace_normal_cylinder(t_ray ray, t_figure *fig)
{
	t_num			maxm;
	t_vec			dis;
	t_vec			v;
	t_vec			m;
	t_vec			p;

	if (fig == NULL)
		return (vec_inf());
	v = vec_normalize(vec_minus(fig->cyl.cap, fig->cyl.pos));
	dis = cylinder_intersect(ray, fig->cyl, v);
	maxm = vec_len(vec_minus(fig->cyl.pos, fig->cyl.cap));
	m = cylinder_m(ray, v, fig->cyl.pos, dis);
	if (dis.x > dis.y)
	{
		dis.x = dis.y;
		m.x = m.y;
	}
//	if (m.x < 0 || m.y < 0)
//		return (vec_mult(v, -1));
//	else if (m.x > maxm || m.y > maxm)
//		return (v);
	if (m.x < 0)
		return (vec_mult(v, -1));
	else if (m.x > maxm)
		return (v);
	p = vec_plus(ray.pos, vec_mult(ray.dir, dis.x));
//	p = vec_plus(ray.pos, vec_mult(ray.dir, dis.x < dis.y ? dis.x : dis.y));
	return (cylinder_side_nrm(p, fig->cyl.pos, v, m.x));
//	return (cylinder_side_nrm(p, fig->cyl.pos, v, dis.x < dis.y ? m.x : m.y));
}