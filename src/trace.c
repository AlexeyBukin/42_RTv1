/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 21:44:51 by kcharla          ###   ########.fr       */
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
    (void)ray;

    if (base->type != FIG_PLANE)
	{
		t_dot tmp_dot = trace_fig(rtv1, ray, rtv1_scene_fig_at(rtv1, id));
		double dist = 1.0 / d3_dist(tmp_dot, ray.pos);
		t_color dist_col = color((t_byte)dist, (t_byte)dist, (t_byte)dist);
		return (color_add(base->col, dist_col));
	}
    t_ray bounce = rtv1_scene(rtv1)->func_trace_bounce[FIG_PLANE](ray, rtv1_scene_fig_at(rtv1, id));
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
    if (cos_a > 0 && cos_a < 1)
	{
		t_color dist_col = base->col;
//		t_byte mask = (ft_absd(cos_a) > 1 ? 1 : ft_absd(cos_a)) * 255;
		t_byte mask = 255;
		dist_col = color_add(base->col, color(mask, mask, mask));
		return (dist_col);
	}
    //bounce = rtv1->scene->func_trace_bounce[base->type](ray, (t_base_fig*)base);
//	i = 0;
//	light_amount = 0;
//	ft_putendl("trace(): start");
//	while (rtv1->scene->lights[i] != NULL)
//	{
//		light_amount += trace_light(rtv1->scene->lights[i], bounce);
//	}
//	ft_putendl("trace(): start");
//	if (light_amount > 255)
//		light_amount = 255;
    //mask = color(light_amount, light_amount, light_amount);
    return (base->col);
    //return (color_mask(base->col, mask));
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
