/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/18 19:34:27 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		trace(t_rtv1 *rtv1, t_double3 direction)
{
	static int iters = 0;
	iters++;

	if (rtv1 == NULL)
	{
		ft_putendl("trace(): pointer rtv1 is NULL");
		return (color(0, 0, 0));
	}


	double		plane_normal[4] = {0.0, 0.0, 0.0, 0.0};


	t_double3 sphere_center = (t_double3) {0.0, 5.0, 0.0};
	double sphere_radius = 2.0;

	plane_normal[0] = direction.x;
	plane_normal[1] = direction.y;
	plane_normal[2] = direction.z;
	plane_normal[3] = direction.x * sphere_center.x +
			direction.y * sphere_center.y + direction.z * sphere_center.z;

	t_double3 args_xyz = d3_mult(rtv1->camera.pos, -1.0);
	t_double3 args_p123 = direction;


	double alpha = plane_normal[0] * args_p123.x + plane_normal[1] * args_p123.y + plane_normal[2] * args_p123.z;
	double left = plane_normal[0] * args_xyz.x + plane_normal[1] * args_xyz.y + plane_normal[2] * args_xyz.z + plane_normal[3];

	alpha = alpha / left;

	t_double3 dot;
	dot.x = args_p123.x * alpha + args_xyz.x;
	dot.y = args_p123.y * alpha + args_xyz.y;
	dot.z = args_p123.z * alpha + args_xyz.z;
	//(void)direction;

	double dist_sqr = d3_dist_sqr(dot, sphere_center);
	if (dist_sqr <= sphere_radius * sphere_radius)
	{
		return (color(0, 255, 0));
	}
	if (iters < 7)
	{
		ft_printf ("dist_sqr is %f, dir is \'%s\'\n", dist_sqr, d3_to_str(direction));
	}
	return (color(40, 40, 40));
}
