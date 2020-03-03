/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/04 01:40:30 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_dot		trace_fig(t_rtv1 *rtv1, t_dot orig, t_vec dir, t_base_fig *fig)
{
	t_figure_base		*base;

	if (fig == NULL || rtv1 == NULL)
	{
		ft_putendl("trace_fig(): pointer rtv1 or fig is NULL");
		return (d3_get_inf());
	}
	base = (t_figure_base*)fig;

	if (base->type == FIG_PLANE)
	{
		return (trace_plane(orig, dir, (t_base_fig_plane*)fig));
	}

	if (base->type == FIG_SPHERE)
	{
		return (trace_sphere(orig, dir, (t_base_fig_sphere*)fig));
	}

	if (base->type == FIG_CYLINDER)
	{
		return (trace_cyl(orig, dir, (t_base_fig_cyl*)fig));
	}
	ft_putendl("trace_fig(): unknown figure");
	return (d3_get_inf());
}

t_color		trace(t_rtv1 *rtv1, t_dot orig, t_vec dir)
{
	t_color			res_col;
	size_t			i;
	t_dot			res;
	double			dist;
	double			new_dist;
	t_base_fig		**figs;

	if (rtv1 == NULL)
	{
		ft_putendl("trace(): pointer rtv1 is NULL");
		return (color(0, 0, 0));
	}
	if ((figs = rtv1_scene_figs(rtv1)) < 0)
	{
		ft_putendl("trace(): pointer rtv1 is NULL");
		return (color(0, 0, 0));
	}
	res_col = color(0, 0, 0);
	dist = RENDER_MAX_DIST;
	i = 0;
	while (figs[i] != NULL)
	{
		res = trace_fig(rtv1, orig, dir, figs[i]);
		new_dist = d3_dist(orig, res);
		if (new_dist < dist)
		{
			dist = new_dist;
			res_col = figs[i]->base.col;
		}
		i++;
	}
	if (dist >= RENDER_MAX_DIST)
		res_col = color(0, 0, 0);
	return (res_col);
}
