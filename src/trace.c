/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/27 08:09:54 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//x = k1*t+b1;
//y = k2*t+b2;
//z = k3*t+b3;

typedef	struct	s_dots3
{
	t_double3	a;
	t_double3	b;
	t_double3	c;
}				t_dots3;

typedef	struct	s_plane
{
	t_dots3		dots;
}				t_plane;

/*
** Function that clamps value from min to max
*/

double	clamp(double val, double min, double max)
{
	if (val < min)
	{
		return (min);
	}
	if (val > max)
	{
		return (max);
	}
	return (val);
}

t_color		trace(t_rtv1 *rtv1, t_double3 X, t_double3 Y)
{
	if (rtv1 == NULL)
	{
		ft_putendl("trace(): pointer rtv1 is NULL");
		return (color(0, 0, 0));
	}

	t_dots3	plane;
	plane.a = (t_double3){4.0, 0.0, 1.0};
	plane.b = (t_double3){4.0, 0.0, 0.0};
	plane.c = (t_double3){3.0, 1.0, 0.0};

//	t_dots3	plane_b;
//	plane.a = (t_double3){4.0, 0.0, 0.0};
//	plane.b = (t_double3){4.0, 0.0, 1.0};
//	plane.c = (t_double3){3.0, -1.0, 0.0};

	t_double3 vec1 = d3_minus(plane.b, plane.a);
	t_double3 vec2 = d3_minus(plane.c, plane.a);
	t_double3 normal = d3_vector_product(vec1, vec2);

	t_double3 V = d3_minus(plane.a, X);

	double d = d3_dot_product(normal, V);

	t_double3 W = d3_minus(Y, X);

	double e = d3_dot_product(normal, W);

	t_double3 O;
	double dist = 0;

	if (e != 0)
	{
		//ft_putendl("trace(): dot found!");
		O = d3_plus(X, d3_mult(W, (double)(d / e)));
		//ft_printf("%-30s - %-30s\n", "dot", d3_to_str_color(O));
		//ft_printf("%-30s - %-30s\n", "dot", d3_to_str_color(O));
		dist = d3_dist(X, O);
		//ft_printf("%-30s - %-30f |", "dist", dist);
		//ft_printf("%-30s - %-30f | ", "X", d3_to_str_color(X));
		//ft_printf("%-30s - %-30f\n", "Y", d3_to_str_color(Y));
		int col = clamp(dist, 0, 10) * 25;
		return (color(col, col, col));

	}
	else
	{
		//ft_putendl("trace(): dot not found!");
		return (color(0, 0, 0));
	}

//	vec1 = d3_minus(plane_b.b, plane_b.a);
//	vec2 = d3_minus(plane_b.c, plane_b.a);
//	normal = d3_vector_product(vec1, vec2);
//
//	V = d3_minus(plane_b.a, X);
//
//	d = d3_dot_product(normal, V);
//
//	W = d3_minus(Y, X);
//
//	e = d3_dot_product(normal, W);
//
//	if (e != 0)
//	{
//		//ft_putendl("trace(): dot found!");
//		O = d3_plus(X, d3_mult(W, (double)(d / e)));
//		//ft_printf("%-30s - %-30s\n", "dot", d3_to_str_color(O));
//		//ft_printf("%-30s - %-30s\n", "dot", d3_to_str_color(O));
//		double dist2 = d3_dist(X, O);
//
//		if (dist2 < dist)
//			dist = dist2;
//		//ft_printf("%-30s - %-30f |", "dist", dist);
//		//ft_printf("%-30s - %-30f | ", "X", d3_to_str_color(X));
//		//ft_printf("%-30s - %-30f\n", "Y", d3_to_str_color(Y));
//
//		int col = clamp(dist, 0, 10) * 25;
//		return (color(col, col, col));
//	}
//	else
//	{
//		//ft_putendl("trace(): dot not found!");
//		return (color(0, 0, 0));
//	}







	//double		plane_normal[4] = {0.0, 0.0, 0.0, 0.0};


//	t_double3 sphere_center = (t_double3) {20.0, 0.0, 0.0};
//	double sphere_radius = 1.0;
//
//	plane_normal[0] = direction.x;
//	plane_normal[1] = direction.y;
//	plane_normal[2] = direction.z;
//	plane_normal[3] = direction.x * sphere_center.x +
//			direction.y * sphere_center.y + direction.z * sphere_center.z;
//
//	//t_double3 args_xyz = d3_mult(rtv1->camera.pos, -1.0);
//	t_double3 args_xyz = rtv1->camera.pos;
//	t_double3 args_p123 = direction;
//
//
//	double alpha = plane_normal[0] * args_p123.x + plane_normal[1] * args_p123.y + plane_normal[2] * args_p123.z;
//	double left = plane_normal[0] * args_xyz.x + plane_normal[1] * args_xyz.y + plane_normal[2] * args_xyz.z + plane_normal[3];
//
//	alpha = alpha / left;
//
//	t_double3 dot;
//	dot.x = args_p123.x * alpha + args_xyz.x;
//	dot.y = args_p123.y * alpha + args_xyz.y;
//	dot.z = args_p123.z * alpha + args_xyz.z;
//	//(void)direction;
//
//	double dist_sqr = d3_dist_sqr(dot, sphere_center);
//	if (dist_sqr <= sphere_radius * sphere_radius) //1
//	{
//		return (color(0, 255, 0));
//	}
//
//	if (rtv1->trace == TRUE)
//	{
//		ft_printf ("%-30s is %-30f | ", "dist_sqr", dist_sqr);
//		ft_printf ("%-30s is %-30s\n", "dir", d3_to_str_color(direction));
//	}
	return (color(40, 40, 40));
}
