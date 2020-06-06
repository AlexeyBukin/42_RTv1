/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 16:40:56 by hush              #+#    #+#             */
/*   Updated: 2020/06/06 18:27:08 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


t_num ggx_distribution(t_num cosThetaNH, t_num alpha) {
	t_num alpha2 = alpha * alpha;
	t_num NH_sqr = num_clamp(num_sqr(cosThetaNH * cosThetaNH), 0, 1);
	t_num den = NH_sqr * alpha2 + (1.0 - NH_sqr);
	return (alpha2 / ( M_PI * den * den ));
}

t_num	ggx_partial_geometry(t_num cos_theta_n, t_num alpha)
{
	cos_theta_n = num_clamp(num_sqr(cos_theta_n), 0, 1);
	cos_theta_n = ( 1 - cos_theta_n ) / cos_theta_n;
	return (2.0 / ( 1.0 + sqrt( 1.0 + alpha * alpha * cos_theta_n)));
}

// n is normal, v is vector to camera
// l is vector to light

t_num	brdf_get_g(t_vec n, t_vec v, t_vec l, t_material *mat)
{
	t_num	g;
	t_num	roug_sqr;

	if (mat == NULL)
		return (INFINITY);
	roug_sqr = num_sqr(mat->roughness);
	g = ggx_partial_geometry(vec_dot_product(n,v), roug_sqr);
	g = g * ggx_partial_geometry(vec_dot_product(n,l), roug_sqr);
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
	d = ggx_distribution(vec_dot_product(n, h), roug_sqr);
	return (d);
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
//	res = (d * f * g) / (4.0 * vec_dot_product(v, n) * vec_dot_product(n, l));
//	return (res);
//}

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
