/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 16:40:56 by hush              #+#    #+#             */
/*   Updated: 2020/06/09 23:22:21 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

//функция расчета затухания для источника света
//t_num GetAttenuation(t_num distance, t_num lightInnerR, t_num invLightOuterR)
//{
//	t_num d = num_max(distance, lightInnerR);
//	return num_clamp(1.0 - pow(d * invLightOuterR, 4.0), 0, 1) / (d * d + 1.0);
//}

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

t_vec cook_torrance_ggx(t_vec n, t_vec l, t_vec v, t_material *m)
{
	t_num		rough_sqr;
	t_num		d;
	t_num		g;
	t_vec		f;
	t_vec		h;

	n = vec_normalize(n);
	l = vec_normalize(l);
	v = vec_normalize(v);
	h = vec_normalize(vec_plus(v, l));

	t_num n_dot_v = vec_dot(n, v);
	t_num n_dot_l = vec_dot(n, l);
	t_num h_dot_v = vec_dot(h, v);

	if (n_dot_l <= 0 || n_dot_v <= 0)
		return (vec_zero());

	rough_sqr = num_sqr(m->roughness);

	d = ggx_distribution(vec_dot(n, h), rough_sqr);

	g = ggx_partial_geometry(n_dot_v, rough_sqr);
	g = g * ggx_partial_geometry(n_dot_l, rough_sqr);

	f = fresnel_schlick(m->f0, h_dot_v);

	t_vec specK = vec_mult_num(f, g * d * 0.25 / (n_dot_v + 0.001));

	t_vec diffK = vec_clamp(vec_minus(vec(1.0, 1.0, 1.0), f), 0.0, 1.0);
	diffK = vec_mult(m->albedo, diffK);
	diffK = vec_mult_num(diffK, n_dot_l / M_PI);

	t_vec res = vec_plus(specK, diffK);
	return (res);
}

// k = (D * F * G) / (4 * (V * N) * (N * L))

t_col		rt_trace_mode_ggx(t_scene *scene, t_ray cam_ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		dist;
	t_vec		to_light;
	t_vec		to_view;
	size_t		i;
	t_num		dist_to_shadow;
	t_num		dist_to_light;
	t_num		light_amount;

	if ((nearest = rt_trace_nearest_dist(scene, cam_ray, &dist)) != NULL)
	{
		normal.pos = vec_plus(cam_ray.pos, vec_mult_num(cam_ray.dir, dist - 0.001));
		normal.dir = trace_normal_fig(cam_ray, nearest);
		t_vec res = vec_zero();
		i = 0;
		while (i < scene->light_num)
		{
			if (ray_point_is_behind(normal, scene->lights[i].pos))
			{
				i++;
				continue ;
			}
			to_light = vec_minus(scene->lights[i].pos, normal.pos);
			dist_to_light = vec_len(to_light);

			if (rt_trace_nearest_dist(scene, ray(normal.pos, to_light), &dist_to_shadow) != NULL)
			{
				if (dist_to_shadow < dist_to_light)
				{
					i++;
					continue ;
				}
			}
			to_view = vec_invert(cam_ray.dir);
			t_vec ggx_res = cook_torrance_ggx(normal.dir, to_view, to_light, nearest->mat);

//			light_amount = 2.0;
			light_amount = scene->lights[i].power / (dist_to_light * dist_to_light + 1.0);

			//todo to_light -> light_amount
			res = vec_plus(res, vec_mult_num(ggx_res, light_amount));
			i++;
		}
		res = vec_clamp(res, 0, 1);
		return (col_from_vec_norm(vec_to_srgb(res)));
	}
	return (col(0, 0, 0));
}

t_col		rt_trace_brdf_d(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		dist;
	t_vec		to_light;
	t_vec		to_view;

	if ((nearest = rt_trace_nearest_dist(scene, ray, &dist)) != NULL)
	{
		normal.pos = vec_plus(ray.pos, vec_mult_num(ray.dir, dist));
		normal.dir = trace_normal_fig(ray, nearest);

		t_num		d = 0.0;
		size_t		i;
		i = 0;
		while (i < scene->light_num)
		{
			if (ray_point_is_behind(normal, scene->lights[i].pos))
			{
				i++;
				continue;
			}

			to_light = vec_minus(scene->lights[i].pos, normal.pos);
			to_view = vec_invert(ray.dir);
			d += brdf_get_d(normal.dir, to_view, to_light, nearest->mat);
			i++;
		}

		return (col_from_vec_norm((t_vec){d, d, d}));
	}
	return (col(0, 0, 0));
}

t_col		rt_trace_brdf_g(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		dist;
	t_vec		to_light;
	t_vec		to_view;

	if ((nearest = rt_trace_nearest_dist(scene, ray, &dist)) != NULL)
	{
		normal.pos = vec_plus(ray.pos, vec_mult_num(ray.dir, dist));
		normal.dir = trace_normal_fig(ray, nearest);

		t_num		g = 0.0;
		size_t		i;
		i = 0;
		while (i < scene->light_num)
		{
			if (ray_point_is_behind(normal, scene->lights[i].pos))
			{
				i++;
				continue;
			}
			to_light = vec_minus(scene->lights[i].pos, normal.pos);
			to_view = vec_invert(ray.dir);
			g += brdf_get_g(normal.dir, to_view, to_light, nearest->mat);
			i++;
		}
		return (col_from_vec_norm((t_vec){g, g, g}));
	}
	return (col(0, 0, 0));
}
