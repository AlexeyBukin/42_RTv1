/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:05:54 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 03:08:26 by hush             ###   ########.fr       */
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
	scene->cameras = (t_camera*)ft_malloc(sizeof(t_camera));
	if (scene->cameras == NULL)
		return (ft_puterror(3, "cannot malloc cameras"));
	camera_set_default(&(scene->cameras[0]));
	if (scene_camera_config(&(scene->cameras[0])) < 0)
		return (ft_puterror(4,"cannot configure camera"));
	scene->cam_num = 1;
	scene->figures = NULL;
	scene->fig_num = 0;
	scene->lights = NULL;
	scene->light_num = 0;
	return (0);
}

t_scene		*scene_init()
{
	t_scene		*scene;

	scene = (t_scene*)ft_malloc(sizeof(t_scene));
	if (scene == NULL)
		return (ft_puterr_null(1, "scene_create():"
								  "cannot malloc scene struct"));
	scene->materials = (t_material*)ft_malloc(sizeof(t_material));
	if (scene->materials == NULL)
		return (ft_puterr_null(2, "scene_create(): cannot malloc materials"));
	scene->mat_num = 1;
	material_set_default(&(scene->materials[0]));
	scene->cameras = (t_camera*)ft_malloc(sizeof(t_camera));
	if (scene->cameras == NULL)
		return (ft_puterr_null(3, "scene_create(): cannot malloc cameras"));
	camera_set_default(&(scene->cameras[0]));
	if (scene_camera_config(&(scene->cameras[0])) < 0)
		return (ft_puterr_null(4,"scene_create(): cannot configure camera"));
	scene->cam_num = 1;
	scene->figures = NULL;
	scene->fig_num = 0;
	scene->lights = NULL;
	scene->light_num = 0;
	return (scene);
}

void		scene_free(t_scene *scene)
{
	if (scene == NULL)
		return ;
	ft_free(scene->figures);
	ft_free(scene->materials);
	ft_free(scene->lights);
	ft_free(scene);
}

char		*scene_to_str(t_scene *scene)
{
	size_t		i;
	char		*res;

	if (scene == NULL)
		return (ft_strdup("(null)"));
	res = ft_strdup("scene:  \'");
	res = ft_str_add(res, scene->filename);
	res = ft_str_add(res, "\'\n{\n  Materials:");
	i = 0;
	while (i < scene->mat_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, material_to_str(&(scene->materials[i++])));
	}
	res = ft_str_add(res, "\n  Lights:");
	i = 0;
	while (i < scene->light_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, light_to_str(&(scene->lights[i++])));
	}
	res = ft_str_add(res, "\n  Cameras:");
	i = 0;
	while (i < scene->cam_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, camera_to_str(&(scene->cameras[i++])));
	}
	res = ft_str_add(res, "\n  Figures:");
	i = 0;
	while (i < scene->fig_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, figure_to_str(&(scene->figures[i++])));
	}
	res = ft_str_add(res, "\n}\n");
	return (res);
}
