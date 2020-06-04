/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 04:16:09 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/04 03:10:28 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			project(t_rt *rtv1)
{
	t_ray		ray;
	t_vec		dot;
	t_camera	*cam;
	t_col		traced;
	int			y;
	int			x;

	if (rtv1 == NULL)
		return (ft_puterror(1, "project(): rtv1 pointer is NULL"));
	if (rtv1->window == NULL)
		return (ft_puterror(2, "project(): rtv1->window pointer is NULL"));
	cam = rtv1->scene_active->cameras;
	y = -1;

	int pixel_num = 0;

	while (++y < WIN_HEIGHT && (x = -1) == -1)
	{
		while (++x < WIN_WIDTH)
		{
			double xd = (double) x;
			double yd = (double) y;
			t_vec dot_1 = vec_mult_num(cam->dir_right,
									  (double) cam->size_x * ((double) (xd / WIN_WIDTH) - (1.0 / 2.0)));

			t_vec dot_2 = vec_plus(dot_1, vec_mult_num(cam->dir_up,
								   (double) -1 * cam->size_y * ((double) (yd / WIN_HEIGHT) - (1.0 / 2.0))));

			dot = vec_plus(cam->plane_pos, dot_2);

			rtv1->flags.trace = FALSE;

			if (x == WIN_WIDTH / 2 && y == WIN_HEIGHT / 2)
			{
				rtv1->flags.trace = TRUE;
			}

			ray.pos = cam->pos;
			ray.dir = vec_normalize(vec_minus(dot, cam->pos));
			traced = rt_trace(rtv1->scene_active, ray);
			texture_put_pixel(rtv1->window->texture, traced, x, y);

			pixel_num++;

		}
	}
	return (0);
}
