/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:48:52 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/03 16:04:16 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** FOV = 90 degrees
*/


// rtv1->camera.direction = d3_minus(rtv1->camera.plane_pos, rtv1->camera.pos);

int			camera_move_local(t_camera *cam, t_vec dir)
{
	t_vec newdir = (t_vec){0, 0, 0};
	if (cam == NULL)
		return (ft_puterror(1, "camera_move(): pointer is NULL"));
	newdir = d3_plus(newdir, d3_mult(d3_normalize(cam->direction), dir.x));
	newdir = d3_plus(newdir, d3_mult(d3_normalize(cam->direction_up), dir.z));
	newdir = d3_plus(newdir, d3_mult(d3_normalize(cam->direction_right), dir.y));
	cam->pos = d3_plus(cam->pos, newdir);
	cam->plane_pos = d3_plus(cam->plane_pos, newdir);
	return (OK);
}

int			camera_move_global(t_camera *cam, t_vec dir)
{
	if (cam == NULL)
		return (ft_puterror(1, "camera_move(): pointer is NULL"));
	cam->pos = d3_plus(cam->pos, dir);
	cam->plane_pos = d3_plus(cam->plane_pos, dir);
	return (OK);
}

int			camera_init_static(t_camera *cam)
{
	if (cam == NULL)
		return (ft_puterror(1, "camera_init_static(): cam pointer is NULL"));
	cam->pos = (t_dot) {0.0, 0.0, 0.0};
//	cam->direction = (t_double3) {1.0, 0.0, 0.0};
	cam->plane_pos = (t_dot) {(double)WIN_WIDTH / 100 / 2, 0.0, 0};
	cam->direction = d3_minus(cam->plane_pos, cam->pos);
	cam->size_x = (double)WIN_WIDTH / 100;
	cam->size_y = (double)WIN_HEIGHT / 100;
	cam->direction_right = (t_vec) {0.0, 1.0, 0.0};
	cam->direction_up = (t_vec) {0.0, 0.0, 1.0};
	return (OK);
}
