/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:04:16 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 03:34:53 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_dot				trace_plane(t_dot orig, t_vec dir, t_base_fig *fig)
{
	t_base_fig_plane	*pl;
	t_vec				normal;
	t_double3			v;
	t_double3			intersect;
	double				e;

	if (fig == NULL)
		return (d3_get_inf());
	pl = (t_base_fig_plane*) fig;
	if (pl->type != FIG_PLANE)
		return (d3_get_inf());
	normal = vec_cross_product(d3_minus(pl->a, pl->pos),
		d3_minus(pl->b, pl->pos));
	v = d3_minus(pl->pos, orig);
	e = vec_dot_product(normal, dir);
	if (e <= 0)
		return (d3_get_inf());
	intersect = d3_plus(orig,
	d3_mult(dir, (double)(vec_dot_product(normal, v) / e)));
	return (intersect);
}

t_base_fig_plane	*fig_plane_create(void)
{
	t_base_fig_plane		*plane;

	if ((plane = (t_base_fig_plane*)fig_create()) == NULL)
		return (ft_puterr_null(1, "fig_plane_create(): cannot"
		" malloc scene struct"));
	plane->type = FIG_PLANE;
	plane->pos = (t_dot){4.0, 0.0, -2.0};
	plane->a = (t_dot){7.0, 1.0, -2.0};
	plane->b = (t_dot){6.0, 0.0, -2.0};
	plane->col = color(0, 200, 0);
	return (plane);
}
