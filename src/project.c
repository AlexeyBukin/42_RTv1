/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 04:16:09 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/18 21:00:08 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
			dot = d3_plus(cam.plane_pos, d3_mult(cam.direction_x,
					cam.size_x * ((x / WIN_WIDTH) - (1 / 2))));
			dot = d3_plus(dot, d3_mult(cam.direction_y,
					cam.size_y * ((y / WIN_HEIGHT) - (1 / 2))));
			traced = trace(rtv1, d3_minus(dot, cam.pos)); ///d3_minus = zero (0) !!!!!!!!!!!!!
			texture_put_pixel(rtv1->window->texture, traced, x, y);

			if (x < 6 && y == 0)
			{
				ft_printf ("cam.pos is \'%s\'\n", d3_to_str(cam.pos));
				ft_printf ("dot is \'%s\'\n", d3_to_str(dot));
//				ft_printf ("dot is \'%s\'\n", d3_to_str(dot));
			}

//			if (y < 5 && x < 5)
//			{
//				//char * str = ft_itoa(color_to_int(traced));
//				printf("%#x\t\t", color_to_int(traced));
//				//free(str;)
//			}
		}
//		if (y < 6)
//		{
//			printf("\n");
//		}
	}
	return (0);
}
