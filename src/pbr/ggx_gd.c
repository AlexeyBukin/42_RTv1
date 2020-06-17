/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 16:40:56 by hush              #+#    #+#             */
/*   Updated: 2020/06/18 00:05:31 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_col		rt_trace_brdf_d(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		dist;
	t_num		d;
	size_t		i;

	if ((nearest = rt_trace_nearest_dist(scene, ray, &dist)) == NULL)
		return (col(0, 0, 0));
	normal.pos = vec_plus(ray.pos, vec_mult_num(ray.dir, dist));
	normal.dir = trace_normal_fig(ray, nearest);
	d = 0.0;
	i = 0;
	while (i < scene->light_num)
	{
		if (ray_point_is_behind(normal, scene->lights[i].pos))
		{
			i++;
			continue;
		}
		d += brdf_get_d(normal.dir, vec_invert(ray.dir),
			vec_minus(scene->lights[i].pos, normal.pos), nearest->mat);
		i++;
	}
	return (col_from_vec_norm(vec(d, d, d)));
}

t_col		rt_trace_brdf_g(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		dist;
	t_num		g;
	size_t		i;

	if ((nearest = rt_trace_nearest_dist(scene, ray, &dist)) == NULL)
		return (col(0, 0, 0));
	normal.pos = vec_plus(ray.pos, vec_mult_num(ray.dir, dist));
	normal.dir = trace_normal_fig(ray, nearest);
	g = 0.0;
	i = 0;
	while (i < scene->light_num)
	{
		if (ray_point_is_behind(normal, scene->lights[i].pos))
		{
			i++;
			continue;
		}
		g += brdf_get_g(normal.dir, vec_invert(ray.dir),
			vec_minus(scene->lights[i].pos, normal.pos), nearest->mat);
		i++;
	}
	return (col_from_vec_norm(vec(g, g, g)));
}
