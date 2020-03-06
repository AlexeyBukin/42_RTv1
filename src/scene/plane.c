/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:31:21 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 19:32:52 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** TODO redo normally
*/

t_ray				trace_plane_bounce(t_ray ray, t_base_fig *fig)
{
	(void)fig;
	return (ray);
}

t_dot				trace_plane(t_ray ray, t_base_fig *fig)
{
	t_base_fig_plane	*pl;
	double				denom;
	double				t;

	if (fig == NULL)
		return (d3_get_inf());
	pl = (t_base_fig_plane*)fig;
	if (pl->type != FIG_PLANE)
		return (d3_get_inf());
	denom = vec_dot_product(pl->n, ray.dir);
	if (ft_absd(denom) < EPSILON)
		return (d3_get_inf());
	t = -1 * (vec_dot_product(pl->n, ray.pos) + pl->d) / denom;
	if (t < EPSILON)
		return (d3_get_inf());
	return (d3_plus(ray.pos, d3_mult(ray.dir, t)));
}

t_base_fig			*fig_plane_create(t_vec normal, double arg_d, t_color col)
{
	t_base_fig_plane		*plane;

	if ((plane = (t_base_fig_plane*)fig_create()) == NULL)
		return (ft_puterr_null(1, "fig_plane_create(): cannot"
		" malloc scene struct"));
	plane->type = FIG_PLANE;
	plane->d = arg_d;
	plane->n = normal;
	plane->col = col;
	return ((t_base_fig*)plane);
}

t_base_fig			*fig_plane_from_dots(t_dot a, t_dot b, t_dot c, t_color col)
{
	double arg_a;
	double arg_b;
	double arg_c;
	double arg_d;

	arg_a = (b.y - a.y) * (c.z - a.z) - (c.y - a.y) * (b.z - a.z);
	arg_b = (b.z - a.z) * (c.x - a.x) - (c.z - a.z) * (b.x - a.x);
	arg_c = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	arg_d = -1 * (arg_a * a.x + arg_b * a.y + arg_c * a.z);
	return (fig_plane_create(vec(arg_a, arg_b, arg_c), arg_d, col));
}
