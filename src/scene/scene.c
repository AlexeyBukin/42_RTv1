/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:14:45 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 15:13:56 by hush             ###   ########.fr       */
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

//	if ((scene->figures = fig_arr_create(3)) == NULL)
//		return (ft_puterr_null(1, "scene_create():"
//		"cannot malloc figures array"));
//	scene->figures[0] = (t_base_fig*)fig_sphere_create();
//	scene->figures[1] = (t_base_fig*)fig_plane_create(dot(4.0, 0.0, -2.0), dot(7.0, 1.0, -2.0), dot(6.0, 0.0, -2.0), color(0, 100, 0));
//	scene->figures[2] = (t_base_fig*)fig_cyl_create();

    if ((scene->figures = fig_arr_create(6)) == NULL)
        return (ft_puterr_null(1, "scene_create():"
                                  "cannot malloc figures array"));
    scene->figures[0] = (t_base_fig*)fig_plane_create(vec(0, 1, 0), 3.0, color(100, 100, 0));
    scene->figures[1] = (t_base_fig*)fig_plane_create(vec(0, -1, 0), 3.0, color(100, 0, 0));
    scene->figures[2] = (t_base_fig*)fig_plane_create(vec(0, 0, 1), 3.0, color(0, 100, 0));
    scene->figures[3] = (t_base_fig*)fig_plane_create(vec(0, 0, -1), 5.0, color(0, 100, 100));
    scene->figures[4] = (t_base_fig*)fig_plane_create(vec(-1, 0, 0), 20.0, color(100, 100, 100));

    scene->figures[5] = (t_base_fig*)fig_sphere_create(dot(5, 1, 1), 1.0, color(100, 0, 100));

//    scene->figures[5] = (t_base_fig*)fig_sphere_create();
//    scene->figures[6] = (t_base_fig*)fig_cyl_create();


	if ((scene->lights = light_arr_create(1)) == NULL)
		return (ft_puterr_null(1, "scene_create():"
		"cannot malloc figures array"));
	scene->lights[0] = light_create();

	scene->func_trace_dot[FIG_SPHERE] = trace_sphere;
	scene->func_trace_dot[FIG_PLANE] = trace_plane;
	scene->func_trace_dot[FIG_CYLINDER] = trace_cyl;

	scene->func_trace_bounce[FIG_SPHERE] = trace_sphere_bounce;
	scene->func_trace_bounce[FIG_PLANE] = trace_plane_bounce;
	return (scene);
}

/*
** TODO smart arrays for storage lights and scene
*/
