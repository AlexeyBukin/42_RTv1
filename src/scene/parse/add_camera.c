/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 00:43:39 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 15:50:12 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "rt_camera.h"

static int
parse_camera(char **source, t_camera *camera)
{
	char 			*text;

	if (source == NULL || camera == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if ((text = *source) == NULL)
		return (ft_puterror(2, "Dereference to NULL pointer"));
	text += ft_strlen(KEYWORD_CAMERA);
	if (*(text++) != '(')
		return (ft_puterror(3, "Expected \'(\' "));
	if (read_vec(&text, &(camera->pos)) < 0)
		return (ft_puterror(4, "Expected position vector "));
	if (!read_comma(&text))
		return (ft_puterror(5, "Expected \',\' "));
	if (read_vec(&text, &(camera->dir)) < 0)
		return (ft_puterror(6, "Expected dir vector"));
	if (!read_comma(&text))
		return (ft_puterror(7, "Expected \',\' "));
	if (read_vec(&text, &(camera->dir_up)) < 0)
		return (ft_puterror(8, "Expected up vector"));
	if (*(text++) != ')')
		return (ft_puterror(9, "Expected \')\' "));
	*source = text;
	return (0);
}

//int
//scene_camera_config(t_camera *cam)
//{
////	cam->pos = (t_vec) {0.0, 0.0, 0.0};
////	cam->dir = (t_vec) {0.0, 0.0, 0.0};
////	cam->dir_up = (t_vec) {0.0, 0.0, 0.0};
//	if (cam == NULL)
//		return (ft_puterror(1, "Entered NULL pointer"));
//	cam->size_x = (double)WIN_WIDTH / 100.0;
//	cam->size_y = (double)WIN_HEIGHT / 100.0;
//
//	if (vec_is_zero(cam->dir) || vec_isinf(cam->dir))
//		return (ft_puterror(2, "Expected correct vector dir"));
//	cam->dir = vec_normalize(cam->dir);
//	if (vec_is_zero(cam->dir_up) || vec_isinf(cam->dir_up))
//		return (ft_puterror(3, "Expected correct vector dir_up"));
//	cam->dir_up = vec_normalize(cam->dir_up);
//	cam->dir_right = vec_cross_product(cam->dir, cam->dir_up);
//	if (vec_is_zero(cam->dir_right) || vec_isinf(cam->dir_right))
//		return (ft_puterror(4, "Cannot configure dir_right"));
//	cam->dir_right = vec_normalize(cam->dir_right);
//	cam->projection = PROJECTION_PERSPECTIVE;
//	cam->mode = COLOR_MODE_FULL_TRACE;
//
//	//todo remove deprecated
//	cam->plane_pos = vec_mult_num(cam->dir,(double)WIN_WIDTH / 100.0 / 2.0);
//	return (0);
//}

int
scene_add_camera(t_scene *scene, char **source)
{
	if (scene == NULL)
		return (ft_puterror(1,"scene is NULL pointer"));
	scene->cameras = ft_realloc_arr(scene->cameras, scene->cam_num,
			scene->cam_num + 1, sizeof(t_camera));
	if (scene->cameras == NULL)
		return (ft_puterror(1,"Realloc cameras returned NULL"));
	scene->cameras[scene->cam_num].id = scene->cam_num;
	if (parse_camera(source, &(scene->cameras[scene->cam_num])) < 0)
		return (ft_puterror(2, "Cannot read camera"));
	if (camera_config(&(scene->cameras[scene->cam_num])) < 0)
		return (ft_puterror(3,"Cannot configure camera"));
	scene->cam_num++;
	return (0);
}
