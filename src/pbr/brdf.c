/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 16:40:56 by hush              #+#    #+#             */
/*   Updated: 2020/06/09 14:45:39 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"



// n is normal, v is vector to camera
// l is vector to light

//float3 diffK = saturate(1.0-F);
//return max(0.0, m.albedo*diffK*NL/PI + specK);

/*
** vec_angle_cos(h, v) is used in UE4
** vec_angle_cos(h, v) is used in Frostbyte
** I found f = fresnel_schlick(m->f0, vec_angle_cos(n, l)); best
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

	rough_sqr = m->roughness * m->roughness;

	d = ggx_distribution(vec_dot(n, h), rough_sqr);

	g = ggx_partial_geometry(n_dot_v, rough_sqr);
	g = g * ggx_partial_geometry(n_dot_l, rough_sqr);

	f = fresnel_schlick(m->f0, vec_angle_cos(n, l));

	t_vec specK = vec_mult_num(f, g * d * 0.25 / (n_dot_v));

	t_vec diffK = vec_clamp(vec_minus(vec(1.0, 1.0, 1.0), f), 0.0, 1.0);
	diffK = vec_mult(m->albedo, diffK);
	diffK = vec_mult_num(diffK, n_dot_l / M_PI);
	t_vec res = vec_max(vec_zero(), vec_plus(diffK, specK));
	return (res);
//	t_vec res = vec_max(vec_zero(),  specK);
//	return (vec_to_srgb(vec(g, g, g)));
}

// k = (D * F * G) / (4 * (V * N) * (N * L))

t_col		rt_trace_mode_ggx(t_scene *scene, t_ray cam_ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		dist;
	t_vec		to_light;
	t_vec		to_view;

	if ((nearest = rt_trace_nearest_dist(scene, cam_ray, &dist)) != NULL)
	{
		normal.pos = vec_plus(cam_ray.pos, vec_mult_num(cam_ray.dir, dist - 0.001));
		normal.dir = trace_normal_fig(cam_ray, nearest);

		t_vec res = vec_zero();

		size_t		i;
		i = 0;
		while (i < scene->light_num)
		{
			if (ray_point_is_behind(normal, scene->lights[i].pos))
			{
				i++;
				continue ;
			}

			to_light = vec_minus(scene->lights[i].pos, normal.pos);

			t_num		dist_to_shadow;
			t_figure	*nearest_fig_shadow;
//			if (rt_trace_nearest_dist(scene, (t_ray){normal.pos, to_light}, &dist) != NULL)
			if ((nearest_fig_shadow = rt_trace_nearest_dist(scene, ray(normal.pos, to_light), &dist_to_shadow)) != NULL)
			{

				//dist /= 10;
				//res = vec(dist, dist, dist);
//				int t = nearest_fig_shadow->type;
//				t_num 	dist2 = dist;
				t_num	dist_to_light = vec_len(to_light);
				if (dist_to_shadow < dist_to_light)
				{
					//i = i;
					//return (col_from_vec_norm(vec_to_srgb(vec(0.1, 0.1, 0.1))));
					//return (col_from_vec_norm(vec_to_srgb(vec(0.2, 0.2, 0.2))));
					i++;
					continue ;
				}
//				else
//				{
//					return (col_from_vec_norm(vec_to_srgb(vec(0.9, 0.9, 0.9))));
//				}

				//	res = vec(0, 0, 0);
//				if (dist < vec_dist_sqr(vec_zero(), to_light))
//				{
//					i++;
//					continue ;
//				}
			}

			to_view = vec_invert(cam_ray.dir);
			res = vec_plus(res, cook_torrance_ggx(normal.dir, to_view, to_light, nearest->mat));
			i++;
		}
		res = vec_clamp(res, 0, 1);
		return (col_from_vec_norm(vec_to_srgb(res)));
	}
	return (col(0, 0, 0));
}


t_num		brdf_get_g(t_vec n, t_vec v, t_vec l, t_material *mat)
{
	t_num	g;
	t_num	roug_sqr;

	if (mat == NULL)
		return (INFINITY);
	roug_sqr = num_sqr(mat->roughness);
	g = ggx_partial_geometry(vec_dot(n, v), roug_sqr);
	g = g * ggx_partial_geometry(vec_dot(n, l), roug_sqr);
	return (g);
}

t_num		brdf_get_d(t_vec n, t_vec v, t_vec l, t_material *mat)
{
	t_num	d;
	t_num	roug_sqr;
	t_vec	h;


	if (mat == NULL)
		return (INFINITY);
	h = vec_normalize(vec_plus(v, l));
	roug_sqr = num_sqr(mat->roughness);
	d = ggx_distribution(vec_dot(n, h), roug_sqr);
	return (d);
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

		if (ray_point_is_behind(normal, scene->lights[0].pos))
		{
			return (col(0, 0, 0));
		}

		to_light = vec_minus(scene->lights[0].pos, normal.pos);
		to_view = vec_invert(ray.dir);
		t_num d = brdf_get_d(normal.dir, to_view, to_light, nearest->mat);
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

		if (ray_point_is_behind(normal, scene->lights[0].pos))
		{
			return (col(0, 0, 0));
		}

		to_light = vec_minus(scene->lights[0].pos, normal.pos);
		to_view = vec_invert(ray.dir);
		t_num g = brdf_get_g(normal.dir, to_view, to_light, nearest->mat);
		return (col_from_vec_norm((t_vec){g, g, g}));
	}
	return (col(0, 0, 0));
}
