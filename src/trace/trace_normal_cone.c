/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_normal_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:33:29 by hush              #+#    #+#             */
/*   Updated: 2020/06/17 23:42:32 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec				trace_normal_cone(t_ray ray_in, t_figure *fig)
{
	t_vec			v;
	t_vec			point_p;
	t_vec			ca;
	t_num			cg;
	t_num			cr;

	if (fig == NULL)
		return (vec_inf());
	v = vec_minus(fig->cone.cap, fig->cone.pos);
	ray_in.dir = vec_normalize(ray_in.dir);
	point_p = vec_plus(ray_in.pos, vec_mult_num(ray_in.dir,
		trace_dot_cone(ray_in, fig)));
	cg = vec_len(v);
	cr = (t_num)sqrt((double)(num_sqr(fig->cone.r) + num_sqr(cg)));
	ca = vec_mult_num(vec_normalize(v),
		(cg * vec_len(vec_minus(point_p, fig->cone.pos)) / cr));
	return (vec_normalize(vec_minus(point_p, vec_plus(fig->cone.pos, ca))));
}
