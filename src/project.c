/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 04:16:09 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/17 05:51:42 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_double3	plus(t_double3 a, t_double3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_double3	minus(t_double3 a, t_double3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_double3	mult(t_double3 a, double b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}

int			project(t_rtv1 *rtv1)
{
	t_double3	dot;
	t_camera	cam;
	t_color		traced;
	int			y;
	int			x;

	if (rtv1 == NULL)
		return (ft_puterror(1, "project(): rtv1 pointer is NULL"));
	if (rtv1->window == NULL)
		return (ft_puterror(2, "project(): rtv1->window pointer is NULL"));
	cam = rtv1->camera;
	y = -1;
	while (++y < WIN_HEIGHT && (x = -1) == -1)
	{
		while (++x < WIN_WIDTH)
		{
			dot = plus(cam.plane_pos, mult(cam.direction_x,
					cam.size_x * ((x / WIN_WIDTH) - (1 / 2))));
			dot = plus(dot, mult(cam.direction_y,
					cam.size_y * ((y / WIN_HEIGHT) - (1 / 2))));
			traced = trace(rtv1, minus(dot, cam.pos));
			texture_put_pixel(rtv1->window->texture, traced, x, y);
		}
	}
	return (0);
}
