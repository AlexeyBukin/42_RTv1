/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace_modes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:00:42 by hush              #+#    #+#             */
/*   Updated: 2020/06/17 23:34:48 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_col		rt_trace_mode_normals_angle(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;
	t_vec		normal;
	t_num		angle_in;

	if ((nearest = rt_trace_nearest(scene, ray)) != NULL)
	{
		normal = trace_normal_fig(ray, nearest);
		angle_in = 1.0 - vec_angle_cos(normal, vec_invert(ray.dir));
		return (col_from_vec(vec(angle_in * 256, 0, 0)));
	}
	return (col(0, 0, 0));
}

t_col		rt_trace_mode_normals(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;

	if ((nearest = rt_trace_nearest(scene, ray)) != NULL)
	{
		return (col_from_normal(trace_normal_fig(ray, nearest)));
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
	t_ray		normal;
	t_vec		res;
	t_num		light_amount;
	t_num		dist;
	size_t		i;

	if (rt_trace_nearest_dist(scene, ray, &dist) != NULL)
	{
		res = vec_zero();
		normal.pos = vec_plus(ray.pos, vec_mult_num(ray.dir, dist));
		i = 0;
		while (i < scene->light_num)
		{
			dist = vec_len(vec_minus(scene->lights[i].pos, normal.pos));
			light_amount = scene->lights[i].power / (dist * dist + 1.0);
			res = vec_plus(res, vec(light_amount, light_amount, light_amount));
			i++;
		}
		return (col_from_vec_norm(res));
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
