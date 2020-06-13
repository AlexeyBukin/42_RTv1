/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 00:43:39 by hush              #+#    #+#             */
/*   Updated: 2020/06/13 13:52:54 by hush             ###   ########.fr       */
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
	if (read_comma(&text) < 0)
		return (ft_puterror(5, "Expected \',\' "));
	if (read_vec(&text, &(camera->dir)) < 0)
		return (ft_puterror(6, "Expected dir vector"));
	if (read_comma(&text) < 0)
		return (ft_puterror(7, "Expected \',\' "));
	if (read_vec(&text, &(camera->dir_up)) < 0)
		return (ft_puterror(8, "Expected up vector"));
	if (*(text++) != ')')
		return (ft_puterror(9, "Expected \')\' "));
	*source = text;
	return (0);
}

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
