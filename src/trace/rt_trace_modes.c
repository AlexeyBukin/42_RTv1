/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_modes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:00:42 by hush              #+#    #+#             */
/*   Updated: 2020/06/09 12:46:41 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

t_col		rt_trace_mode_full(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		dist;

	if ((nearest = rt_trace_nearest_dist(scene, ray, &dist)) != NULL)
	{
		normal.pos = vec_plus(ray.pos, vec_mult_num(ray.dir, dist));
		normal.dir = trace_normal_fig(ray, nearest);
		return (trace_bounce(scene, ray, normal, nearest->mat));
	}
	return (col(0, 0, 0));
}

t_col		rt_trace_mode_normals(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;
	t_vec		normal;

	if ((nearest = rt_trace_nearest(scene, ray)) != NULL)
	{
		normal = trace_normal_fig(ray, nearest);
		return (col_from_normal(normal));
	}
	return (col(0, 0, 0));
}

t_col		rt_trace_mode_color_only(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;

	if ((nearest = rt_trace_nearest(scene, ray)) != NULL)
	{
		if (nearest->mat != NULL)
			return (col_from_vec_norm(nearest->mat->albedo));
	}
	return (col(0, 0, 0));
}

t_col		rt_trace_mode_light(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		dist;

	if ((nearest = rt_trace_nearest_dist(scene, ray, &dist)) != NULL)
	{
		normal.pos = vec_plus(ray.pos, vec_mult_num(ray.dir, dist));
		normal.dir = trace_normal_fig(ray, nearest);
		t_col res = trace_bounce(scene, ray, normal, nearest->mat);
		//todo return vec, check if vec nums > 1
		return (res);
	}
	return (col(0, 0, 0));
}

t_col		rt_trace_mode_dist(t_scene *scene, t_ray ray)
{
	t_num		dist;

	if (rt_trace_nearest_dist(scene, ray, &dist) != NULL)
	{
		dist = num_max(dist, 1);
		dist = 1 / dist;
		return (col_from_vec_norm(vec(dist, dist, dist)));
	}
	return (col(0, 0, 0));
}