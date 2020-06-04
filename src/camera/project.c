/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 04:16:09 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/04 21:59:39 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray		project_get_ray_from_coords(t_camera *cam, double x, double y)
{
	t_ray		ray;
	t_vec		dot;
	t_vec		dot_1;
	t_vec		dot_2;

	dot_1 = vec_mult_num(cam->dir_right,
			(double) cam->size_x * ((double) (x / WIN_WIDTH) - (1.0 / 2.0)));

	dot_2 = vec_plus(dot_1, vec_mult_num(cam->dir_up,
	(double) -1 * cam->size_y * ((double) (y / WIN_HEIGHT) - (1.0 / 2.0))));
	dot = vec_plus(cam->plane_pos, dot_2);
	ray.pos = cam->pos;
	ray.dir = vec_normalize(vec_minus(dot, cam->pos));
	return (ray);
}

int			project_scene(t_scene *scene)
{
	t_ray		ray;
	t_camera	*cam;
	size_t		y;
	size_t		x;

	if (scene == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if ((cam = scene->cam_active) == NULL)
		return (ft_puterror(2, "Scene's main camera is NULL"));

	if (cam->texture == NULL)
		return (ft_puterror(3, "Camera's texture is NULL"));
		//cam->texture = texture_init(WIN_WIDTH, WIN_HEIGHT);

	texture_fill(cam->texture, col(0, 0, 0));
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = project_get_ray_from_coords(cam, x, y);
			texture_put_pixel(cam->texture, rt_trace(scene, ray), x, y);
			x++;
		}
		y++;
	}
	return (0);
}
