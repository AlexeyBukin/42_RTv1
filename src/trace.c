/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/02 16:48:54 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_double3		trace_sphere(t_double3 orig, t_double3 dir, t_base_fig_sphere s)
{
	t_double3	ao;
//	t_double3	ab;
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
	//ab = d3_minus(b, a);
	dir = d3_normalize(dir);


	dist = d3_len(ao);
	square = d3_dot_product(ao, dir);

	cos_a = square / (dist);

	//sin(acos(cos_a))
	sin_a = sqrt(1.0 - cos_a * cos_a);
	perp = dist * sin_a;
	if (perp > s.r)
	{
		return(d3_get_inf());
	}

	ac_len = dist * cos_a;
	c = d3_plus(orig, d3_mult(dir, ac_len));

	root = sqrt(s.r * s.r - perp * perp);
	result = d3_minus(c, d3_mult(dir, root));
	return (result);
}

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

t_double3		trace_cyl(t_double3 orig, t_double3 dir, t_base_fig_cyl *cyl)
{
	t_double3	ao;
	t_double3	ab;
	t_double3	ao_x_ab;
	t_double3	v_x_ab;
	//t_double3	res;

	if (cyl == NULL)
		return (d3_get_inf());
	dir = d3_normalize(dir);
	ab = d3_minus(cyl->top, cyl->pos);
	ao = d3_minus(orig, cyl->pos);

	ao_x_ab = d3_vector_product(ao, ab);
	v_x_ab = d3_vector_product(dir, ab);

	double ab2 = d3_dot_product(ab, ab);
	double a   = d3_dot_product(v_x_ab, v_x_ab);
	double b   = 2.0 * d3_dot_product(v_x_ab, ao_x_ab);
	double c   = d3_dot_product(ao_x_ab, ao_x_ab) - (cyl->r * cyl->r * ab2);

	double d   = b * b - 4.0 * a * c;

	if (d < 0)
	{
		return (d3_get_inf());
	}

	double t = (-b - sqrt(d)) / (2 * a);
	if (t < 0)
	{
		return (d3_get_inf());
	}
	t_double3 i_pos     = d3_plus(d3_mult(dir, t), orig);

	t_double3 i_pos_len = d3_minus(i_pos, cyl->pos);
	double    t_lim     = d3_dot_product(i_pos_len, ab) / ab2;

	if (t_lim >= 0 && t_lim <= 1)
		{
			return (i_pos);
		}
	return (d3_get_inf());
	//return (res);
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
