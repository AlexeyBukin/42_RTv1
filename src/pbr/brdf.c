/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 16:40:56 by hush              #+#    #+#             */
/*   Updated: 2020/06/18 00:51:13 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**  n is normal
**  l is vector to light
**  v is vector to camera
*/

/*
** vec_angle_cos(h, v) is used in UE4
** vec_angle_cos(h, l) is used in Frostbyte
** basically they are the same
*/

/*
** specular = (D * F * G) / (4 * (V * N) * (N * L))
*/

t_vec			cook_torrance_ggx(t_vec n, t_vec l, t_vec v, t_material *m)
{
	t_num		g;
	t_vec		f_diffk;
	t_num		n_dot_v;
	t_num		n_dot_l;
	t_vec		speck;

	n = vec_normalize(n);
	l = vec_normalize(l);
	v = vec_normalize(v);
	n_dot_v = vec_dot(n, v);
	n_dot_l = vec_dot(n, l);
	if (n_dot_l <= 0 || n_dot_v <= 0)
		return (vec_zero());
	g = ggx_partial_geometry(n_dot_v, num_sqr(m->roughness));
	g = g * ggx_partial_geometry(n_dot_l, num_sqr(m->roughness));
	f_diffk = fresnel_schlick(m->f0, vec_dot(vec_normalize(vec_plus(v, l)), v));
	speck = vec_mult_num(f_diffk, g *
	ggx_distribution(vec_dot(n, vec_normalize(vec_plus(v, l))),
		num_sqr(m->roughness)) * 0.25 / (n_dot_v + 0.001));
	f_diffk = vec_clamp(vec_minus(vec(1.0, 1.0, 1.0), f_diffk), 0.0, 1.0);
	f_diffk = vec_mult(m->albedo, f_diffk);
	f_diffk = vec_mult_num(f_diffk, n_dot_l / M_PI);
	return (vec_plus(speck, f_diffk));
}

static t_vec	rt_trace_mode_ggx_loop(t_ggx_loop info)
{
	t_vec		to_light;
	t_vec		to_view;
	t_num		dist_to_shadow;
	t_num		dist_to_light;
	t_num		light_amount;

	if (info.lamp == NULL)
		return (vec_zero());
	if (ray_point_is_behind(info.normal, info.lamp->pos))
		return (vec_zero());
	to_light = vec_minus(info.lamp->pos, info.normal.pos);
	dist_to_light = vec_len(to_light);
	if (rt_trace_nearest_dist(info.scene,
		ray(info.normal.pos, to_light), &dist_to_shadow) != NULL)
	{
		if (dist_to_shadow < dist_to_light)
		{
			return (vec_zero());
		}
	}
	to_view = vec_invert(info.cam_ray.dir);
	light_amount = info.lamp->power / (dist_to_light * dist_to_light + 1.0);
	return (vec_mult_num(cook_torrance_ggx(info.normal.dir, to_light,
		to_view, info.mat), light_amount));
}

t_col			rt_trace_mode_ggx(t_scene *scene, t_ray cam_ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		dist;
	size_t		i;
	t_vec		res;

	if ((nearest = rt_trace_nearest_dist(scene, cam_ray, &dist)) == NULL)
		return (col(0, 0, 0));
	normal.pos = vec_plus(cam_ray.pos,
		vec_mult_num(cam_ray.dir, dist - 0.0001));
	normal.dir = trace_normal_fig(cam_ray, nearest);
	res = vec_zero();
	i = 0;
	while (i < scene->light_num)
	{
		res = vec_plus(res, rt_trace_mode_ggx_loop((t_ggx_loop){
			normal, cam_ray, scene, &(scene->lights[i]), nearest->mat
		}));
		i++;
	}
	res = vec_clamp(res, 0, 1);
	return (col_from_vec_norm(vec_to_srgb(res)));
}
