/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/02 18:06:39 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_double3		trace_sphere(t_double3 orig, t_double3 dir, t_base_fig_sphere s)
{
	t_double3	ao;
	double		cos_a;
	double		sin_a;
	double		dist;
	double		perp;
	double		square;
	double		root;
	double		ac_len;
	t_double3	c;
	t_double3	result;

	ao = d3_minus(s.pos, orig);
	dir = d3_normalize(dir);
	dist = d3_len(ao);
	square = d3_dot_product(ao, dir);
	cos_a = square / (dist);
	sin_a = sqrt(1.0 - cos_a * cos_a);
	perp = dist * sin_a;
	if (perp > s.r)
		return(d3_get_inf());
	ac_len = dist * cos_a;
	c = d3_plus(orig, d3_mult(dir, ac_len));
	root = sqrt(s.r * s.r - perp * perp);
	result = d3_minus(c, d3_mult(dir, root));
	return (result);
}


//TODO array of figures
t_color		trace(t_rtv1 *rtv1, t_double3 orig, t_double3 dir)
{
	if (rtv1 == NULL)
	{
		ft_putendl("trace(): pointer rtv1 is NULL");
		return (color(0, 0, 0));
	}
	t_double3	res;
//	t_base_fig_plane pl;
//	pl.pos  = (t_double3){4.0, 0.0, 0.0};
//	pl.a    = (t_double3){3.0, 0.0, 1.0};
//	pl.b    = (t_double3){4.0, 1.0, 0.0};

//    pl.pos  = (t_double3){0.0, 0.0, 0.0};
//    pl.a    = (t_double3){1.0, 0.0, 0.0};
//    pl.b    = (t_double3){0.0, 1.0, 0.0};
//	pl.type = FIG_PLANE;
//	pl.col  = color(0, 100, 0);

//	t_base_fig_sphere sphere;
//	sphere.type = FIG_SPHERE;
//	sphere.pos = (t_double3) {4.0, 0.0, 0.0};
//	sphere.r = 2;
//	sphere.col = color(100, 0, 0);
//
//
//	res = trace_sphere(orig, dir, sphere);

	t_base_fig_cyl  *cyl;
	cyl = fig_cyl_create();
	res = trace_cyl(orig, dir, cyl);

	//res = trace_plane(orig, dir, pl);

	if (d3_is_inf(res))
	{
		return (color(0, 0, 0));
	}
	double dist = d3_dist(orig, res);
	int col = (double)(clamp(dist, 0.0, 25) * 10.0);
	return (col_mask(color(col + 100, col + 100, col + 100), cyl->col));
	//return (color_alpha(255, 255, 255, 100));
}
