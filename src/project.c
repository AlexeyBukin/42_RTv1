/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 04:16:09 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/18 23:51:16 by kcharla          ###   ########.fr       */
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
			double xd = (double) x;
			double yd = (double) y;
			t_double3 dot_1 = d3_mult(cam.direction_right,
									  (double) cam.size_x * ((double) (xd / WIN_WIDTH) - (1.0 / 2.0)));

			t_double3 dot_2 = d3_plus(cam.plane_pos, dot_1);
			dot = d3_plus(dot_2, d3_mult(cam.direction_up,
					(double) cam.size_y * ((double) (yd / WIN_HEIGHT) - (1.0 / 2.0))));



			traced = trace(rtv1, d3_minus(dot, cam.pos)); ///d3_minus = zero (0) !!!!!!!!!!!!!
			texture_put_pixel(rtv1->window->texture, traced, x, y);

			//TODO wtf? make this!
			static int iters = 0;
			iters++;
			int needed = WIN_WIDTH / 3;
			if (iters % needed == 0 && iters < WIN_WIDTH)
			{
				double xd = (double) x;
				ft_printf ("x               is \'%f\'\n", (double)(x));
				ft_printf ("xd              is \'%f\'\n", xd);
				ft_printf ("(x / WIN_WIDTH) is \'%f\'\n", (double)(x / WIN_WIDTH));
				ft_printf ("(xd / WIN_WIDTH)is \'%f\'\n", (double)(xd / WIN_WIDTH));
				ft_printf ("cam.pos         is \'%s\'\n", d3_to_str_color(cam.pos));
				ft_printf ("cam.plane_pos   is \'%s\'\n", d3_to_str_color(cam.plane_pos));
				ft_printf ("dot_1           is \'%s\'\n", d3_to_str_color(dot_1));
				ft_printf ("dot_2           is \'%s\'\n", d3_to_str_color(dot_2));
				ft_printf ("cam.direction_r is \'%s\'\n", d3_to_str_color(cam.direction_right));
				ft_printf ("cam.direction_upis \'%s\'\n", d3_to_str_color(cam.direction_up));
				ft_printf ("dot_1           is \'%s\'\n", d3_to_str_color(dot_1));
				ft_printf ("dot             is \'%s\'\n", d3_to_str_color(dot));
				ft_printf ("\n");
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
