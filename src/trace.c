/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 15:14:48 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

size_t		trace_light(t_light *light, t_ray ray)
{
	(void)light;
	(void)ray;
	return (1);
}

t_dot		trace_fig(t_rtv1 *rtv1, t_ray ray, t_base_fig *fig)
{
	if (fig == NULL || rtv1 == NULL)
		return (d3_get_inf());
	if (rtv1->scene == NULL)
		return (d3_get_inf());
	if (rtv1->scene->func_trace_dot[fig->base.type] == NULL)
		return (d3_get_inf());
	return (rtv1->scene->func_trace_dot[fig->base.type](ray, fig));
}

t_color		trace_full(t_rtv1 *rtv1, t_ray ray, size_t id)
{
    //t_color			mask;
//	t_ray			bounce;
    t_figure_base	*base;
//	size_t			i;
//	size_t 			light_amount;

    if (rtv1 == NULL)
        return (color(0, 0, 0));
    if (rtv1->scene == NULL)
        return (color(0, 0, 0));
    if (rtv1->scene->figures == NULL || rtv1->scene->lights == NULL)
        return (color(0, 0, 0));
    base = (t_figure_base*)rtv1_scene_fig_at(rtv1, id);
    if (base == NULL)
        return (color(0, 0, 0));

	//t_ray bounce = rtv1_scene(rtv1)->func_trace_bounce[base->type](ray, rtv1_scene_fig_at(rtv1, id));

    if (base->type != FIG_PLANE && base->type != FIG_SPHERE)
	{
		t_dot tmp_dot = trace_fig(rtv1, ray, rtv1_scene_fig_at(rtv1, id));
		double dist = 1.0 / d3_dist(tmp_dot, ray.pos);
		t_color dist_col = color((t_byte)dist, (t_byte)dist, (t_byte)dist);
		return (color_add(base->col, dist_col));
	}
    t_ray bounce = rtv1_scene(rtv1)->func_trace_bounce[base->type](ray, rtv1_scene_fig_at(rtv1, id));
    t_vec bounce_to_light = d3_minus(rtv1_scene(rtv1)->lights[0]->point.pos, bounce.pos);

    double cos_a = vec_angle_cos(bounce.dir, bounce_to_light);

    if (rtv1->trace == TRUE)
	{
    	ft_printf("cos = %f\n", cos_a);
    	ft_printf("angle = %f\n", acos(cos_a));
    	ft_printf("ray_dir = %s\n", d3_to_str_color(ray.dir));
    	ft_printf("bounce = %s\n", d3_to_str_color(bounce.dir));
    	ft_printf("to_light = %s\n", d3_to_str_color(bounce_to_light));
	}

	double light_koeff = 3.0;
    double light_power = 1.0 / (vec_len(bounce_to_light) + EPSILON) * light_koeff;

    //diffuse
	cos_a = (cos_a + 1) / 2;
	t_byte mask = cos_a * 255;
	mask = (mask * light_power > 255 ? 255 : mask * light_power);
	t_color mask_col = color_add(color(mask, mask, mask), color(1, 1, 1));
	t_color dist_col = col_mask(base->col, mask_col);

	//real light
	double shine_bound = 0.9;
	if (cos_a > shine_bound)
	{
		double koeff = (cos_a - shine_bound) / (1.0 - shine_bound);
//		if (koeff > 0.5)
//			ft_printf("more\n");
		t_byte additive = clamp(koeff * 255, 0, 255);
//		additive = (additive * 100 > 255 ? 255 : additive * 100);
		additive = (additive * light_power > 255 ? 255 : additive * light_power);
		dist_col = color_add(dist_col, color(additive, additive, additive));
	}

	return (dist_col);
}

int			get_nearest_id(t_rtv1 *rtv1, t_ray ray)
{
	t_double3	tmp_dot;
	double		tmp_dist;
	double		res_dist;
	int			res_id;
	size_t		i;

	res_id = -1;
	res_dist = get_inf();
	i = 0;
	while (rtv1_scene_fig_at(rtv1, i) != NULL)
	{
		tmp_dot = trace_fig(rtv1, ray, rtv1_scene_fig_at(rtv1, i));
		if ((tmp_dist = d3_dist(ray.pos, tmp_dot)) < res_dist)
		{
			res_dist = tmp_dist;
			res_id = i;
		}
		i++;
	}
	return (res_id);
}

t_color		trace(t_rtv1 *rtv1, t_ray ray)
{
	int		res_id;

	if (rtv1 == NULL)
	{
		ft_putendl("trace(): pointer rtv1 is NULL");
		return (color(0, 0, 0));
	}
	res_id = get_nearest_id(rtv1, ray);
	if (res_id < 0)
		return (color(0, 0, 0));
	return (trace_full(rtv1, ray, res_id));
}
