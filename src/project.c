/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 04:16:09 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/03 21:00:22 by kcharla          ###   ########.fr       */
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

	int pixel_num = 0;

	while (++y < WIN_HEIGHT && (x = -1) == -1)
	{
		while (++x < WIN_WIDTH)
		{
			double xd = (double) x;
			double yd = (double) y;
			t_double3 dot_1 = d3_mult(cam.direction_right,
									  (double) cam.size_x * ((double) (xd / WIN_WIDTH) - (1.0 / 2.0)));

			t_double3 dot_2 = d3_plus(dot_1, d3_mult(cam.direction_up,
								   (double) -1 * cam.size_y * ((double) (yd / WIN_HEIGHT) - (1.0 / 2.0))));

			dot = d3_plus(cam.plane_pos, dot_2);

//			int needed = WIN_WIDTH / 5;
//			if (pixel_num % needed == 0 && pixel_num < WIN_WIDTH)
//			{
//				rtv1->trace = TRUE;
//			}
//			else
//			{
//				rtv1->trace = FALSE;
//			}

			rtv1->trace = FALSE;

			if (x == 0 && y == 0)
			{
				rtv1->trace = TRUE;
			}

			if (x == WIN_WIDTH - 1 && y == 0)
			{
				rtv1->trace = TRUE;
			}

			if (x == 0 && y == WIN_HEIGHT - 1)
			{
				rtv1->trace = TRUE;
			}

			if (x == WIN_WIDTH - 1 && y == WIN_HEIGHT - 1)
			{
				rtv1->trace = TRUE;
			}


			traced = trace(rtv1, cam.pos, d3_minus(dot, cam.pos)); ///d3_minus = zero (0) !!!!!!!!!!!!!
			texture_put_pixel(rtv1->window->texture, traced, x, y);

			//TODO manual tracing with debuging

			//int needed = WIN_WIDTH / 3;
//			if (rtv1->trace == TRUE)
//			{
//				double xd = (double) x;
//				ft_printf ("%-30s is %-30f | ", "xd", xd);
//				ft_printf ("%-30s is %-30f\n", "yd", yd);
//				ft_printf ("%-30s is %-30d | ", "x", x);
//				ft_printf ("%-30s is %-30d\n", "y", y);
//				ft_printf ("%-30s is %-30s\n", "cam.pos", d3_to_str_color(cam.pos));
//				ft_printf ("%-30s is %-30s\n", "cam.plane_pos", d3_to_str_color(cam.plane_pos));
//				ft_printf ("%-30s is %-30s\n", "dot1", d3_to_str_color(dot_1));
//				ft_printf ("%-30s is %-30s\n", "dot2", d3_to_str_color(dot_2));
//				ft_printf ("%-30s is %-30s\n", "dot", d3_to_str_color(dot));
//				ft_printf ("%-30s is %-30s\n", "dir", d3_to_str_color(d3_minus(dot, cam.pos)));
//				ft_printf ("\n");
////				ft_printf ("dot is \'%s\'\n", d3_to_str(dot));
//			}
			pixel_num++;

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
	return (OK);
}
