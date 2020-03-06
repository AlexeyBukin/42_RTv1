/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 04:13:43 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		trace_full(t_rtv1 *rtv1, t_double3 orig, t_double3 dir, size_t id)
{
	t_figure_base	*base;

	if (rtv1 == NULL)
		return (color(0, 0, 0));
	if (rtv1->scene == NULL)
		return (color(0, 0, 0));
	if (rtv1->scene->figures == NULL)
		return (color(0, 0, 0));
	base = (t_figure_base*)rtv1->scene->figures[id];
	if (base == NULL)
		return (color(0, 0, 0));
	(void)dir;
	(void)orig;
	return (base->col);
}

t_dot		trace_fig(t_rtv1 *rtv1, t_dot orig, t_vec dir, t_base_fig *fig)
{
	if (fig == NULL || rtv1 == NULL)
		return (d3_get_inf());
	if (rtv1->scene == NULL)
		return (d3_get_inf());
	return (rtv1->scene->func_trace_dist[fig->base.type](orig, dir, fig));
}

int			get_nearest_id(t_rtv1 *rtv1, t_double3 orig, t_double3 dir)
{
	t_double3	tmp_dot;
	double		tmp_dist;
	double		res_dist;
	int			res_id;
	size_t		i;

	res_id = -1;
	if ((res_dist = RENDER_MAX_DIST) < 0)
		res_dist = get_inf();
	i = 0;
	while (rtv1_scene_fig_at(rtv1, i) != NULL)
	{
		tmp_dot = trace_fig(rtv1, orig, dir, rtv1_scene_fig_at(rtv1, i));
		if ((tmp_dist = d3_dist(orig, tmp_dot)) < res_dist)
		{
			res_dist = tmp_dist;
			res_id = i;
		}
		i++;
	}
	return (res_id);
}

t_color		trace(t_rtv1 *rtv1, t_double3 orig, t_double3 dir)
{
	int		res_id;

	if (rtv1 == NULL)
	{
		ft_putendl("trace(): pointer rtv1 is NULL");
		return (color(0, 0, 0));
	}
	res_id = get_nearest_id(rtv1, orig, dir);
	if (res_id < 0)
		return (color(0, 0, 0));
	return (trace_full(rtv1, orig, dir, res_id));
}
