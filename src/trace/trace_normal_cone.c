/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_normal_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:33:29 by hush              #+#    #+#             */
/*   Updated: 2020/06/16 17:54:02 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// m = D|V*t + X|V

static
t_num 				cone_m(t_ray ray, t_vec v, t_vec cone_pos, t_num dist)
{
	t_num			x_dot_v;

	//vec_dot(ray_in.dir, vec_mult_num(v, points.x)) + x_dot_v;
	x_dot_v = vec_dot(vec_minus(ray.pos, cone_pos), v);
//	return (vec_dot(ray.dir, v) * dist + x_dot_v);
	return (vec_dot(ray.dir, vec_mult_num(v, dist)) + x_dot_v);
}

static
t_vec 				cone_side_nrm(t_vec p, t_vec c, t_vec v, t_num mkk)
{
	p = vec_minus(p, c);
	p = vec_minus(p, vec_mult_num(v, mkk));
	return (p);
}

// N = nrm( (P-C) - (1+k*k)*V*m )

#define EPSILON_CONE 0.001
t_vec				trace_normal_cone(t_ray ray, t_figure *fig)
{
	t_num			max_m;
	t_num			dis;
	t_vec			v;
	//t_vec			p;
	t_num			m;
	//t_num			k;
	t_vec			res;

	if (fig == NULL)
		return (vec_inf());
	ray.dir = vec_normalize(ray.dir);
	//k = fig->cone.r / vec_len(vec_minus(fig->cone.pos, fig->cone.cap));
	v = vec_normalize(vec_minus(fig->cone.cap, fig->cone.pos));
//TODO bug fix



	dis = trace_dot_cone(ray, fig);
	max_m = vec_len(vec_minus(fig->cone.pos, fig->cone.cap));
	m = cone_m(ray, v, fig->cone.pos, dis);

	if (m > max_m - EPSILON_CONE)
		return (v);
	//p = vec_plus(vec_mult_num(ray.dir, dis), ray.pos);
	//max_m = fig->cone.r / vec_len(vec_minus(fig->cone.pos, fig->cone.cap));
	//t_num mkk = (k * k + 1) * m;
//	res = vec_minus(vec_minus(p, ray.pos), vec_mult_num(v, mkk));
	res = cone_side_nrm(vec_plus(ray.pos, vec_mult_num(ray.dir, dis)),
		fig->cone.pos, v, max_m);
	res = vec_normalize(res);
	return (res);
}