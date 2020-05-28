/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_normal_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:33:29 by hush              #+#    #+#             */
/*   Updated: 2020/05/29 02:45:32 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static
t_vec 				cone_m(t_ray ray, t_vec v, t_vec cone_pos, t_vec points)
{
	t_num			x_dot_v;
	t_vec			m;

	x_dot_v = vec_dot_product(vec_minus(ray.pos, cone_pos), v);
	m.x = vec_dot_product(ray.dir, vec_mult(v, points.x)) + x_dot_v;
	m.y = vec_dot_product(ray.dir, vec_mult(v, points.y)) + x_dot_v;
	return (m);
}

static
t_vec 				cone_side_nrm(t_vec p, t_vec c, t_vec v, t_num mkk)
{
	p = vec_minus(p, c);
	p = vec_minus(p, vec_mult(v, mkk));
	return (p);
}

// N = nrm( P-C - (1+k*k)*V*m )

t_vec				trace_normal_cone(t_ray ray, t_figure *fig)
{
	t_num			maxm;
	t_vec			dis;
	t_vec			v;
	t_vec			m;
	t_vec			p;

	if (fig == NULL)
		return (vec_inf());
	v = vec_normalize(vec_minus(fig->cone.cap, fig->cone.pos));
	dis = cone_intersect(ray, fig->cone, v);
	maxm = vec_len(vec_minus(fig->cone.pos, fig->cone.cap));
	m = cone_m(ray, v, fig->cone.pos, dis);
	if (m.x > maxm || m.y > maxm)
		return (v);
	p = vec_plus(ray.pos, vec_mult(ray.dir, dis.x < dis.y ? dis.x : dis.y));
	maxm = fig->cone.r / vec_len(vec_minus(fig->cone.pos, fig->cone.cap));
	maxm *= (maxm * maxm + 1) * ((dis.x < dis.y) ? m.x : m.y);
	return (cone_side_nrm(p, fig->cone.pos, v, maxm));
}