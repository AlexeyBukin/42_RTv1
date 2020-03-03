/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:14:45 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/03 20:52:02 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** create and fill scene
*/

t_scene		*scene_create(void)
{
	t_scene		*scene;

	if ((scene = (t_scene*)malloc(sizeof(t_scene))) == NULL)
		return (ft_puterr_null(1, "scene_create():"
		"cannot malloc scene struct"));
	if ((scene->figures = fig_arr_create(3)) == NULL)
		return (ft_puterr_null(1, "scene_create():"
				"cannot malloc figures array"));
	scene->figures[0] = (t_base_fig*)fig_sphere_create();
	scene->figures[1] = (t_base_fig*)fig_plane_create();
	scene->figures[2] = (t_base_fig*)fig_cyl_create();
	scene->figures[3] = NULL;
	scene->lights = NULL;
	return (scene);
}

/*
** TODO smart arrays for storage lights and figures
*/

