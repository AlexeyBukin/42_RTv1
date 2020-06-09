/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_dot_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:10:11 by hush              #+#    #+#             */
/*   Updated: 2020/06/09 16:50:59 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num					trace_dot_plane(t_ray ray, t_figure *fig)
{
	t_plane				*pl;
//	t_num				x_dot_v;
	t_num				d_dot_v;
//	t_num				t;

	if (fig == NULL)
		return (INFINITY);
	pl = &(fig->plane);
	ray.dir = vec_normalize(ray.dir);
	//t_vec		C = vec_mult_num(pl->n, (-1.0 * pl->d));
	//t_vec		X = vec_zero();
	//X = vec_minus(ray.pos, vec_mult_num(pl->n, (-1.0 * pl->d)));

	d_dot_v = vec_dot(ray.dir, pl->n);

//	if (d_dot_v == 0.0)
//		return (INFINITY);
	return (-1 * vec_dot(vec_minus(ray.pos,
		vec_mult_num(pl->n, (-1.0 * pl->d))), pl->n) / d_dot_v);
}

//t_num					trace_dot_plane_old(t_ray ray, t_figure *fig)
//{
//	t_plane				*pl;
//	t_num				denom;
//	t_num				t;
//
//	if (fig == NULL)
//		return (INFINITY);
//	pl = &(fig->plane);
//	denom = vec_dot(pl->n, ray.dir);
//	if (ft_absd(denom) < EPSILON)
//		return (INFINITY);
//	t = -1 * (vec_dot(pl->n, ray.pos) + pl->d) / denom;
//	if (t < EPSILON)
//		return (INFINITY);
//	return (t);
//}

//  d = -(a*x1 + b*y1 + c*z1);

t_num					trace_dot_cap(t_ray ray, t_ray plane_ray)
{
	t_figure		fig;

	fig.type = FIG_PLANE;
	fig.plane.n = plane_ray.dir;
	fig.plane.d = -(plane_ray.dir.x * plane_ray.pos.x + plane_ray.dir.y *
			plane_ray.pos.y	+ plane_ray.dir.z * plane_ray.pos.z);
	return (trace_dot_plane(ray, &fig));
}
