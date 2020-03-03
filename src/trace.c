/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/03 20:59:38 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"




//TODO array of figures
t_color		trace(t_rtv1 *rtv1, t_double3 orig, t_double3 dir)
{
	if (rtv1 == NULL)
	{
		ft_putendl("trace(): pointer rtv1 is NULL");
		return (color(0, 0, 0));
	}
	t_double3	cyl_res;
	t_double3	sp_res;
	t_double3	pl_res;
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

	t_color rescol = color(0, 0, 0);


	t_base_fig_sphere	*sphere = (t_base_fig_sphere*)rtv1->scene->figures[0];
	sp_res = trace_sphere(orig, dir, sphere);

	t_base_fig_plane	*pl = (t_base_fig_plane*)rtv1->scene->figures[1];
	pl_res = trace_plane(orig, dir, pl);

	t_base_fig_cyl		*cyl = (t_base_fig_cyl*)rtv1->scene->figures[2];
	cyl_res = trace_cyl(orig, dir, cyl);

	double dist_sp = d3_dist(orig, sp_res);
	double dist_cyl = d3_dist(orig, cyl_res);
	double dist_pl = d3_dist(orig, pl_res);

	double dist = 100.0;
	if (dist_sp < dist)
	{
		dist = dist_sp;
		rescol = sphere->col;
	}

	if (dist_cyl < dist)
	{
		dist = dist_cyl;
		rescol = cyl->col;
	}

	if (dist_pl < dist)
	{
		dist = dist_pl;
		rescol = pl->col;
	}

	//res = trace_plane(orig, dir, pl);

//	if (d3_is_inf(res))
//	{
//		return (color(0, 0, 0));
//	}
//	double dist = d3_dist(orig, res);
	if (dist > 50)
		return (color(0, 0, 0));
	if (is_inf (dist))
		return (color(0, 0, 0));

	//int col = (int)(clamp(dist, 0.0, 25) * 10.0);
	return (rescol);
	//return (col_mask(color(col + 100, col + 100, col + 100), rescol));
	//return (color_alpha(255, 255, 255, 100));
}
