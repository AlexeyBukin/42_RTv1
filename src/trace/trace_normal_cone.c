/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_normal_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:33:29 by hush              #+#    #+#             */
/*   Updated: 2020/06/15 17:59:32 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static
t_num 				cone_m(t_ray ray, t_vec v, t_vec cone_pos, t_num dist)
{
	t_num			x_dot_v;
	t_num			m;

	x_dot_v = vec_dot(vec_minus(ray.pos, cone_pos), v);
	m = vec_dot(ray.dir, vec_mult_num(v, dist)) + x_dot_v;
	return (m);
}

static
t_vec 				cone_side_nrm(t_vec p, t_vec c, t_vec v, t_num mkk)
{
	p = vec_minus(p, c);
	p = vec_minus(p, vec_mult_num(v, mkk));
	return (p);
}

// N = nrm( (P-C) - (1+k*k)*V*m )

t_vec				trace_normal_cone(t_ray ray, t_figure *fig)
{
	t_num max_m;
	t_num			dis;
	t_vec			v;
	t_num			m;
	//t_vec			p;
	t_vec			res;

	if (fig == NULL)
		return (vec_inf());
	v = vec_normalize(vec_minus(fig->cone.cap, fig->cone.pos));
	dis = trace_dot_cone(ray, fig);
	max_m = vec_len(vec_minus(fig->cone.pos, fig->cone.cap));
	m = cone_m(ray, v, fig->cone.pos, dis);
	if (m > max_m)
		return (v);
	//p = vec_plus(ray.pos, vec_mult_num(ray.dir, dis));
	max_m = fig->cone.r / vec_len(vec_minus(fig->cone.pos, fig->cone.cap));
	max_m *= (max_m * max_m + 1) * m;
	res = cone_side_nrm(vec_plus(ray.pos, vec_mult_num(ray.dir, dis)),
		fig->cone.pos, v, max_m);
	return (res);
}