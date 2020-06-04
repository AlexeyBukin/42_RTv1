/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:48:52 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/04 14:12:23 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** FOV = 90 degrees
*/

// rtv1->camera.dir = d3_minus(rtv1->camera.plane_pos, rtv1->camera.pos);

void		camera_set_default(t_camera	*cam)
{
	if (cam == NULL)
		return ;
	cam->pos = (t_vec) {0.0, 0.0, 0.0};
	cam->plane_pos = vec((double)WIN_WIDTH / 100.0 / 2.0, 0.0, 0.0);
	cam->dir = vec_minus(cam->plane_pos, cam->pos);
	cam->size_x = (double)WIN_WIDTH / 100.0;
	cam->size_y = (double)WIN_HEIGHT / 100.0;
	cam->dir_right = (t_vec) {0.0, 1.0, 0.0};
	cam->dir_up = (t_vec) {0.0, 0.0, 1.0};
	cam->texture = NULL;
}

int			camera_move_local(t_camera *cam, t_vec dir)
{
	t_vec newdir = (t_vec){0, 0, 0};
	if (cam == NULL)
		return (ft_puterror(1, "camera_move(): pointer is NULL"));
	newdir = vec_plus(newdir, vec_mult_num(vec_normalize(cam->dir), dir.x));
	newdir = vec_plus(newdir, vec_mult_num(vec_normalize(cam->dir_up), dir.z));
	newdir = vec_plus(newdir, vec_mult_num(vec_normalize(cam->dir_right), dir.y));
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

t_camera		*camera_init()
{
	t_camera		*cam;

	if ((cam = (t_camera*)ft_malloc(sizeof(t_camera))) == NULL)
		return (ft_puterr_null(1, "camera_init(): Cannot malloc camera"));
	cam->pos = (t_vec) {0.0, 0.0, 0.0};
//	cam->dir = (t_double3) {1.0, 0.0, 0.0};
	cam->plane_pos = vec((double)WIN_WIDTH / 100.0 / 2.0, 0.0, 0.0);
	cam->dir = vec_minus(cam->plane_pos, cam->pos);
	cam->size_x = (double)WIN_WIDTH / 100.0;
	cam->size_y = (double)WIN_HEIGHT / 100.0;
	cam->dir_right = (t_vec) {0.0, 1.0, 0.0};
	cam->dir_up = (t_vec) {0.0, 0.0, 1.0};
	return (cam);
}

void 			camera_delete(t_camera *cam)
{
	if (cam == NULL)
		return ;
	texture_free(cam->texture);
}

void			camera_free(t_camera *cam)
{
	camera_delete(cam);
	ft_free(cam);
}

int				camera_config(t_camera *cam)
{
//	cam->pos = (t_vec) {0.0, 0.0, 0.0};
//	cam->dir = (t_vec) {0.0, 0.0, 0.0};
//	cam->dir_up = (t_vec) {0.0, 0.0, 0.0};
	if (cam == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	cam->size_x = (double)WIN_WIDTH / 100.0;
	cam->size_y = (double)WIN_HEIGHT / 100.0;

	if (vec_is_zero(cam->dir) || vec_isinf(cam->dir))
		return (ft_puterror(2, "Expected correct vector dir"));
	cam->dir = vec_normalize(cam->dir);
	if (vec_is_zero(cam->dir_up) || vec_isinf(cam->dir_up))
		return (ft_puterror(3, "Expected correct vector dir_up"));
	cam->dir_up = vec_normalize(cam->dir_up);
	cam->dir_right = vec_cross_product(cam->dir, cam->dir_up);
	if (vec_is_zero(cam->dir_right) || vec_isinf(cam->dir_right))
		return (ft_puterror(4, "Cannot configure dir_right"));
	cam->dir_right = vec_normalize(cam->dir_right);
	cam->projection = PROJECTION_PERSPECTIVE;
	cam->mode = COLOR_MODE_FULL_TRACE;

	//todo remove deprecated
	cam->plane_pos = vec_mult_num(cam->dir,(double)WIN_WIDTH / 100.0 / 2.0);
	return (0);
}
