/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_normal_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:33:29 by hush              #+#    #+#             */
/*   Updated: 2020/06/16 22:27:22 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec				trace_normal_cone(t_ray ray, t_figure *fig)
{
	t_vec			v;
	t_vec			point_p;
	t_vec			ca;
	t_num			cg;
	t_num			cr;
	t_vec			nrm;

	if (fig == NULL)
		return (vec_inf());
	v = vec_minus(fig->cone.cap, fig->cone.pos);
	ray.dir = vec_normalize(ray.dir);
	point_p = ray.pos, vec_mult_num(ray.dir, trace_dot_cone(ray, fig));
	cg = vec_len(v);
	cr = (t_num)sqrt((double) (num_sqr(fig->cone.r) + num_sqr(cg)));
	ca = vec_mult_num(vec_normalize(v),
		(cg * vec_len(vec_minus(point_p, fig->cone.pos)) / cr));
	nrm = vec_minus(point_p, vec_plus(fig->cone.pos, ca));
	return (vec_normalize(nrm));
}