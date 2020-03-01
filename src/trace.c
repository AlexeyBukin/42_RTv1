/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/01 14:17:03 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_double3		trace_plane(t_double3 from, t_double3 to, t_base_fig_plane pl)
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

//TODO array of planes
t_color		trace(t_rtv1 *rtv1, t_double3 X, t_double3 Y)
{
	if (rtv1 == NULL)
	{
		ft_putendl("trace(): pointer rtv1 is NULL");
		return (color(0, 0, 0));
	}
	t_base_fig_plane pl;
//	pl.pos  = (t_double3){4.0, 0.0, 0.0};
//	pl.a    = (t_double3){3.0, 0.0, 1.0};
//	pl.b    = (t_double3){4.0, 1.0, 0.0};
    pl.pos  = (t_double3){0.0, 0.0, 0.0};
    pl.a    = (t_double3){1.0, 0.0, 0.0};
    pl.b    = (t_double3){0.0, 1.0, 0.0};
	pl.type = FIG_PLANE;
	pl.col  = color(0, 100, 0);

	t_double3	res;

	res = trace_plane(X, Y, pl);

	if (d3_is_inf(res))
	{
		return (color(0, 0, 0));
	}
	double dist = d3_dist(X, res);
	int col = (double)(clamp(dist, 0.0, 25) * 10.0);
	return (color(col, col, col));
}
