/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/01 20:29:55 by hush             ###   ########.fr       */
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

/*
** params.x = cos_normal_bounce
** params.y = cos_bounce_light
** params.z = light power / (distance + 1.0)
*/

t_vec		trace_color_2(t_vec params, t_vec col_base, t_vec col_light, t_vec pbr)
{
	(void)pbr;
	col_light = vec_mult_num(col_light, params.z);
	//TODO pbr
	//params.y = num_map(params.y, vec2d(0.0, 1.0), vec2d(0.5, 1.0));
	col_light = vec_mult_num(col_light, params.y);
	col_base = vec_mult(col_base, col_light);
	return (col_base);
}

/*
** params.x = cos_normal_bounce
** params.y = cos_bounce_light
** params.z = light power / (distance + 1.0)
*/

# define RT_DISTANCE_PARAMETER 0.01
// todo define in light struct

t_col		trace_color(t_ray normal, t_vec bounce, t_material *mat, t_light *light)
{
//	t_num		cos_normal_bounce;
//	t_num		cos_bounce_light;
	t_vec		params;
	t_vec		to_light;
//	t_col		res_col;

	if (mat == NULL || light == NULL)
		return (col(0, 0, 0));
	to_light = vec_minus(light->pos, normal.pos);
//	res_col = col(0, 0, 0);
//	cos_normal_bounce = vec_angle_cos(bounce, normal.dir);
//	cos_bounce_light = vec_angle_cos(bounce, to_light);
//	return (mat->col);
	params.x = vec_angle_cos(bounce, normal.dir);
	//params.y = num_map(vec_angle_cos(bounce, to_light), vec2d(0.0, 1.0), vec2d(0.5, 1.0));
	params.y = vec_angle_cos(bounce, to_light);
//	params.z = 1.0 - (atan(vec_len(to_light) * RT_DISTANCE_PARAMETER) / M_PI * 2.0);
	params.z = 1.0 - (atan(vec_len(to_light) * (1.0 / light->power)) / M_PI * 2.0);
	params.z = params.z * light->power;

	// map(num, vec2d(0, 1))

	to_light = trace_color_2(params, mat->col,
		light->col, *((t_vec*)&(mat->roughness)));
	return (col_from_vec_norm(to_light));
}

t_col		trace_bounce(t_scene *scene, t_ray ray, t_ray normal, t_material *mat)
{
	t_col		res_col;
	size_t		i;
	t_vec		l_dot_n;
	t_vec		bounce;

	if (mat == NULL || scene == NULL)
		return (col(0, 0, 0));

	l_dot_n = vec_mult_num(normal.dir, vec_dot_product(ray.dir, normal.dir) * 2.0);
	bounce = vec_minus(ray.dir, l_dot_n);

	res_col = col(50, 50, 50);
	i = 0;
	while (i < scene->light_num)
	{
		//ft_printf("cycle\n");
		if (ray_point_is_behind(normal, scene->lights[i].pos))
		{
			i++;
			continue ;
		}


//		t_ray to_light;
//		to_light.pos = normal.pos;
//		to_light.dir = vec_minus(scene->lights[i].pos, normal.pos);

//		if (trace_nearest(scene, to_light) != NULL)
//			continue ;
		//(void)bounce;
		t_col additive = trace_color(normal, bounce, mat,&(scene->lights[i]));
		res_col = col_add(res_col, additive);
		i++;
	}
	return (res_col);
}

/*
** NOTE: to use "normals" mode:
**
** if (nearest != NULL)
** 		return (col_from_normal(normal.dir));
**
** For debug only!
*/

t_col		rt_trace(t_scene *scene, t_ray ray)
{
	t_figure	*nearest;
	t_ray		normal;
	t_num		tmp_dist;
	t_num		res_dist;
	size_t		i;

	if (scene == NULL)
		return (col(0, 0, 0));
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
	if (nearest != NULL)
	{
		normal.pos = vec_plus(ray.pos, vec_mult_num(ray.dir, res_dist));
		normal.dir = trace_normal_fig(ray, nearest);
		//return (col_from_normal(normal.dir));
		return (trace_bounce(scene, ray, normal, nearest->mat));
	}
	return (col(0, 0, 0));
}

//t_col		trace_full(t_rt *rtv1, t_ray ray, size_t id)
//{
//    //t_col			mask;
////	t_ray			bounce;
//    t_figure_base	*base;
////	size_t			i;
////	size_t 			light_amount;
//
//    if (rtv1 == NULL)
//        return (col(0, 0, 0));
//    if (rtv1->scene == NULL)
//        return (col(0, 0, 0));
//    if (rtv1->scene->figures == NULL || rtv1->scene->lights == NULL)
//        return (col(0, 0, 0));
//    base = (t_figure_base*)rtv1_scene_fig_at(rtv1, id);
//    if (base == NULL)
//        return (col(0, 0, 0));
//
//	//t_ray bounce = rtv1_scene(rtv1)->func_trace_bounce[base->type](ray, rtv1_scene_fig_at(rtv1, id));
//
//    if (base->type != FIG_PLANE && base->type != FIG_SPHERE)
//	{
//		t_dot tmp_dot = trace_fig(rtv1, ray, rtv1_scene_fig_at(rtv1, id));
//		t_num dist = 1.0 / vec_dist(tmp_dot, ray.pos);
//		t_col dist_col = col((t_byte)dist, (t_byte)dist, (t_byte)dist);
//		return (color_add(base->col, dist_col));
//	}
//    t_ray bounce = rtv1_scene(rtv1)->func_trace_bounce[base->type](ray, rtv1_scene_fig_at(rtv1, id));
//    t_vec bounce_to_light = vec_minus(rtv1_scene(rtv1)->lights[0]->point.pos, bounce.pos);
//
//    t_num cos_a = vec_angle_cos(bounce.dir, bounce_to_light);
//
//    if (rtv1->trace == TRUE)
//	{
//    	ft_printf("cos = %f\n", cos_a);
//    	ft_printf("angle = %f\n", acos(cos_a));
//    	ft_printf("ray_dir = %s\n", vec_to_str_color(ray.dir));
//    	ft_printf("bounce = %s\n", vec_to_str_color(bounce.dir));
//    	ft_printf("to_light = %s\n", vec_to_str_color(bounce_to_light));
//	}
//
//	t_num light_koeff = 3.0;
//    t_num light_power = 1.0 / (vec_len(bounce_to_light) + EPSILON) * light_koeff;
//
//    //diffuse
//	cos_a = (cos_a + 1) / 2;
//
//	//if (cos_a < 0.5)
//	//	cos_a *= 0.5;
//
//	t_byte mask = 200;///cos_a * 255;
//	mask = (mask * light_power > 255 ? 255 : mask * light_power);
//	t_col mask_col = col(mask, mask, mask);
//	//t_col mask_col = color_add(col(mask, mask, mask), col(1, 1, 1));
//	t_col dist_col = col_mask(base->col, mask_col);
//
//	//real light
//	t_num shine_bound = 0.9;
//	if (cos_a > shine_bound)
//	{
//		t_num koeff = (cos_a - shine_bound) / (1.0 - shine_bound);
////		if (koeff > 0.5)
////			ft_printf("more\n");
//		t_byte additive = clamp(koeff * 255, 0, 255);
////		additive = (additive * 100 > 255 ? 255 : additive * 100);
//		additive = (additive * light_power > 255 ? 255 : additive * light_power);
//		dist_col = col_add(dist_col, col(additive, additive, additive));
//	}
//
//	return (dist_col);
//}
