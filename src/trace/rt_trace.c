/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/27 15:55:07 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num		trace_dot_fig(t_rt *rtv1, t_ray ray, t_figure *fig)
{
	if (fig == NULL || rtv1 == NULL)
		return (INFINITY);
	if (rtv1->scene == NULL)
		return (INFINITY);
	if (rtv1->funcs.trace_dot[fig->type] == NULL)
		return (INFINITY);
	return (rtv1->funcs.trace_dot[fig->type](ray, fig));
}

t_vec		trace_normal_fig(t_rt *rtv1, t_ray ray, t_figure *fig)
{
	if (fig == NULL || rtv1 == NULL)
		return (vec_inf());
	if (rtv1->scene == NULL)
		return (vec_inf());
	if (rtv1->funcs.trace_dot[fig->type] == NULL)
		return (vec_inf());
	return (rtv1->funcs.trace_normal[fig->type](ray, fig));
}

t_col		rt_trace(t_rt *rtv1, t_ray ray)
{
	t_figure	*nearest;
	//t_ray		normal;
	t_num		tmp_dist;
	t_num		res_dist;
	size_t		i;

	if (rtv1 == NULL)
		return (col(0, 0, 0));
	if (rtv1->scene == NULL)
		return (col(0, 0, 0));
	if (rtv1->scene->figures == NULL)
		return (col(0, 0, 0));
	nearest = NULL;
	res_dist = INFINITY;
	i = 0;
	while (i < rtv1->scene->fig_num)
	{
		tmp_dist = trace_dot_fig(rtv1, ray, &(rtv1->scene->figures[i]));
		if (tmp_dist < res_dist && tmp_dist > 0)
		{
			res_dist = tmp_dist;
			nearest = &(rtv1->scene->figures[i]);
		}
		i++;
	}
	if (nearest != NULL)
	{
		//normal.pos = vec_plus(ray.pos, vec_mult(ray.dir, res_dist));
		//normal.dir = trace_normal_fig(rtv1, ray, nearest);
		return (nearest->mat->col);
		//return (trace_bounce(rtv1, ray, normal, nearest->mat));
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
