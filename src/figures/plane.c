/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:04:16 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/02 18:06:21 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_double3				trace_plane(t_double3 from, t_double3 to, t_base_fig_plane pl)
{
	t_double3 vec1 = d3_minus(pl.a, pl.pos);
	t_double3 vec2 = d3_minus(pl.b, pl.pos);
	t_double3 normal = d3_vector_product(vec1, vec2);
	t_double3 V = d3_minus(pl.pos, from);
	double d = d3_dot_product(normal, V);
	t_double3 W = d3_minus(to, from);
	double e = d3_dot_product(normal, W);
	if (e == 0)
		return(d3_get_inf());
	t_double3 INTERSECTION;
	INTERSECTION = d3_plus(from, d3_mult(W, (double)(d / e)));
	return (INTERSECTION);
}

t_base_fig_plane		*fig_plane_create(void)
{
	t_base_fig_plane		*plane;

	if ((plane = (t_base_fig_plane*)malloc(sizeof(t_base_fig_plane))) == NULL)
		return (ft_puterr_null(1, "fig_plane_create(): cannot"
		" malloc scene struct"));
	plane->type = FIG_PLANE;
	plane->pos = (t_double3){4.0, 0.0, -1.0};
	plane->a = (t_double3){4.0, 0.0, -1.0};
	plane->b = (t_double3){4.0, 0.0, -1.0};
	plane->col = color(128, 128, 128);
	return (plane);
}
