/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:48:52 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/17 21:52:13 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			camera_move_local(t_camera *cam, t_vec dir)
{
	t_vec newdir;

	newdir = vec_zero();
	if (cam == NULL)
		return (ft_puterror(1, "camera_move(): pointer is NULL"));
	newdir = vec_plus(newdir, vec_mult_num(vec_normalize(cam->dir), dir.x));
	newdir = vec_plus(newdir, vec_mult_num(vec_normalize(cam->dir_up), dir.z));
	newdir = vec_plus(newdir,
		vec_mult_num(vec_normalize(cam->dir_right), dir.y));
	cam->pos = vec_plus(cam->pos, newdir);
	cam->plane_pos = vec_plus(cam->plane_pos, newdir);
	return (0);
}

int			camera_move_global(t_camera *cam, t_vec dir)
{
	if (cam == NULL)
		return (ft_puterror(1, "camera_move(): pointer is NULL"));
	cam->pos = vec_plus(cam->pos, dir);
	cam->plane_pos = vec_plus(cam->plane_pos, dir);
	return (0);
}

void		camera_delete(t_camera *cam)
{
	if (cam == NULL)
		return ;
	texture_free(cam->texture);
}

void		camera_free(t_camera *cam)
{
	camera_delete(cam);
	ft_free(cam);
}

/*
** todo remove deprecated
** cam->plane_pos = vec_mult_num(cam->dir,(double)WIN_WIDTH / 100.0 / 2.0);
*/

/*
** FOV = 90 degrees
*/

int			camera_config(t_camera *cam)
{
	if (cam == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if ((cam->texture = texture_init(WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (ft_puterror(5, "Cannot malloc camera texture"));
	cam->size_x = (double)WIN_WIDTH / 100.0;
	cam->size_y = (double)WIN_HEIGHT / 100.0;
	if (vec_is_zero(cam->dir) || vec_is_inf(cam->dir))
		return (ft_puterror(2, "Expected correct vector dir"));
	cam->dir = vec_normalize(cam->dir);
	if (vec_is_zero(cam->dir_up) || vec_is_inf(cam->dir_up))
		return (ft_puterror(3, "Expected correct vector dir_up"));
	cam->dir_up = vec_normalize(cam->dir_up);
	cam->dir_right = vec_cross(cam->dir_up, cam->dir);
	if (vec_is_zero(cam->dir_right) || vec_is_inf(cam->dir_right))
		return (ft_puterror(4, "Cannot configure dir_right"));
	cam->dir_right = vec_normalize(cam->dir_right);
	cam->projection = PROJECTION_PERSPECTIVE;
	cam->mode = TRACE_MODE_FULL;
	cam->plane_pos = vec_mult_num(cam->dir, (double)WIN_WIDTH / 100.0 / 2.0);
	return (0);
}
