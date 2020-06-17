/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:05:54 by hush              #+#    #+#             */
/*   Updated: 2020/06/17 23:26:42 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		scene_set_default(t_scene *scene)
{
	if (scene == NULL)
		return (ft_puterror(1, "scene is NULL pointer"));
	scene->filename = SCENE_FILENAME_UNSET;
	scene->materials = (t_material*)ft_malloc(sizeof(t_material));
	if (scene->materials == NULL)
		return (ft_puterror(2, "cannot malloc materials"));
	scene->mat_num = 1;
	material_set_default(&(scene->materials[0]));
	scene->cam_active = NULL;
	scene->cameras = NULL;
	scene->cam_num = 0;
	scene->figures = NULL;
	scene->fig_num = 0;
	scene->lights = NULL;
	scene->light_num = 0;
	return (0);
}

void	scene_camera_arr_free(t_scene *scene)
{
	size_t		i;

	if (scene == NULL)
		return ;
	i = 0;
	while (i < scene->cam_num)
	{
		camera_delete(&(scene->cameras[i]));
		i++;
	}
	ft_free(scene->cameras);
}

/*
** scene->filename is NOT freed
*/

void	scene_delete(t_scene *scene)
{
	if (scene == NULL)
		return ;
	scene_camera_arr_free(scene);
	ft_free(scene->figures);
	ft_free(scene->materials);
	ft_free(scene->lights);
}

void	scene_free(t_scene *scene)
{
	scene_delete(scene);
	ft_free(scene);
}
