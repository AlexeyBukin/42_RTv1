/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 23:27:26 by hush              #+#    #+#             */
/*   Updated: 2020/06/17 23:28:49 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static char			*lights_block(t_scene *scene, char *res)
{
	size_t		i;

	res = ft_str_add(res, "\n  Lights: ");
	res = ft_strjoin_free(res, ft_lltoa(scene->light_num));
	i = 0;
	while (i < scene->light_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, light_to_str(&(scene->lights[i++])));
	}
	return (res);
}

static char			*materials_block(t_scene *scene, char *res)
{
	size_t		i;

	res = ft_str_add(res, "\'\n{\n  Materials: ");
	res = ft_strjoin_free(res, ft_lltoa(scene->mat_num));
	i = 0;
	while (i < scene->mat_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, material_to_str(&(scene->materials[i++])));
	}
	return (res);
}

static char			*cameras_block(t_scene *scene, char *res)
{
	size_t		i;

	res = ft_str_add(res, "\n  Cameras: ");
	res = ft_strjoin_free(res, ft_lltoa(scene->cam_num));
	i = 0;
	while (i < scene->cam_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, camera_to_str(&(scene->cameras[i++])));
	}
	return (res);
}

char				*scene_to_str(t_scene *scene)
{
	size_t		i;
	char		*res;

	if (scene == NULL)
		return (ft_strdup("(null)"));
	res = ft_strdup("scene:  \'");
	res = ft_str_add(res, scene->filename);
	res = materials_block(scene, res);
	res = lights_block(scene, res);
	res = cameras_block(scene, res);
	res = ft_str_add(res, "\n  Figures: ");
	res = ft_strjoin_free(res, ft_lltoa(scene->fig_num));
	i = 0;
	while (i < scene->fig_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, figure_to_str(&(scene->figures[i++])));
	}
	res = ft_str_add(res, "\n}\n");
	return (res);
}
