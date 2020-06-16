/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/08 21:00:23 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num		trace_dot_fig(t_ray ray, t_figure *fig)
{
	if (fig == NULL)
		return (INFINITY);
	if (fig->type == FIG_PLANE)
		return (trace_dot_plane(ray, fig));
	else if (fig->type == FIG_SPHERE)
		return (trace_dot_sphere(ray, fig));
	else if (fig->type == FIG_CONE)
		return (trace_dot_cone(ray, fig));
	else if (fig->type == FIG_CYL)
		return (trace_dot_cylinder(ray, fig));
	else
		return (INFINITY);
}

t_vec		trace_normal_fig(t_ray ray, t_figure *fig)
{
	if (fig == NULL)
		return (vec_inf());
	if (fig->type == FIG_PLANE)
		return (trace_normal_plane(ray, fig));
	else if (fig->type == FIG_SPHERE)
		return (trace_normal_sphere(ray, fig));
	else if (fig->type == FIG_CONE)
		return (trace_normal_cone(ray, fig));
	else if (fig->type == FIG_CYL)
		return (trace_normal_cylinder(ray, fig));
	else
		return (vec_inf());
}

t_col		rt_trace(t_scene *scene, t_ray ray, t_trace_mode mode)
{
	if (mode == TRACE_MODE_FULL)
		return (rt_trace_mode_ggx(scene, ray));
	else if (mode == TRACE_MODE_NORMALS)
		return (rt_trace_mode_normals(scene, ray));
	else if (mode == TRACE_MODE_COLOR)
		return (rt_trace_mode_color_only(scene, ray));
	else if (mode == TRACE_MODE_LIGHT)
		return (rt_trace_mode_light(scene, ray));
	else if (mode == TRACE_MODE_DIST)
		return (rt_trace_mode_dist(scene, ray));
	else if (mode == TRACE_MODE_BRDF_G)
		return (rt_trace_brdf_g(scene, ray));
	else if (mode == TRACE_MODE_BRDF_D)
		return (rt_trace_brdf_d(scene, ray));
	else if (mode == TRACE_MODE_NORM_ANGLE)
		return (rt_trace_mode_normals_angle(scene, ray));
	return (col(0, 0, 0));
}

t_figure	*rt_trace_nearest_dist(t_scene *scene, t_ray ray, t_num *dist)
{
	t_figure	*nearest;
	t_num		tmp_dist;
	t_num		res_dist;
	size_t		i;

	if (scene == NULL)
		return (ft_puterr_null(1, "Entered NULL scene pointer"));
	nearest = NULL;
	res_dist = INFINITY;
	i = 0;
	while (i < scene->fig_num)
	{
		tmp_dist = trace_dot_fig(ray, &(scene->figures[i]));
		if (tmp_dist < res_dist && tmp_dist > 0)
		{
			res_dist = tmp_dist;
			nearest = &(scene->figures[i]);
		}
		i++;
	}
	if (dist != NULL)
		*dist = res_dist;
	return (nearest);
}

t_figure	*rt_trace_nearest(t_scene *scene, t_ray ray)
{
	return (rt_trace_nearest_dist(scene, ray, NULL));
}
