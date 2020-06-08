/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 16:40:56 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 23:26:23 by hush             ###   ########.fr       */
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
//	t_vec res = vec_max(vec_zero(),  specK);
	return (vec_to_srgb(res));
//	return (vec_to_srgb(vec(g, g, g)));
}

// k = (D * F * G) / (4 * (V * N) * (N * L))

//t_num	brdf()
//{
//	t_num res;
//	t_num d;
//	t_num f;
//	t_num g;
//	t_vec n;
//	t_vec v;
//	t_vec l;
//	t_vec h;
//
//	h = vec_normalize(vec_plus(v, l));
//	g = brdf_get_g();
//	d = brdf_get_d();
//	f = 0;//get_d();
//
//	res = (d * f * g) / (4.0 * vec_dot_product(v, n) * vec_dot(n, l));
//	return (res);
//}

t_col		rt_trace_mode_ggx(t_scene *scene, t_ray ray)
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
		t_vec res = cook_torrance_ggx(normal.dir, to_view, to_light, nearest->mat);
		return (col_from_vec_norm(res));
	}
	return (col(0, 0, 0));
}


t_num	brdf_get_g(t_vec n, t_vec v, t_vec l, t_material *mat)
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

t_num	brdf_get_d(t_vec n, t_vec v, t_vec l, t_material *mat)
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
