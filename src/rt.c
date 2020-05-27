/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:18:15 by hush              #+#    #+#             */
/*   Updated: 2020/05/27 15:55:07 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rt		*rtv1_init(int ac, char **args)
{
	char 		*scene_path;
	t_rt		*new;

	if ((new = (t_rt*)ft_malloc(sizeof(t_rt))) == NULL)
		return (ft_puterr_null(1, "rtv1_init(): Cannot malloc rtv1"));
	if (ac > 2)
		return (ft_puterr_null(2, "rtv1_init(): Unexpected input..."));
	scene_path = (ac == 1) ? SCENE_DEFAULT : args[1];
	if ((new->scene = scene_from_file(scene_path)) == NULL)
		return (ft_puterr_null(3, "rtv1_init(): Cannot read scene"));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_puterr_null(4, "rtv1_init(): Cannot init SDL_VIDEO"));
	if ((new->window = window_init(WIN_WIDTH, WIN_HEIGHT, scene_path)) == NULL)
		return (ft_puterr_null(5, "rtv1_init(): Cannot init window"));
	if ((new->camera = camera_init()) == NULL)
		return (ft_puterr_null(6, "rtv1_init(): Cannot init camera"));
	new->funcs.trace_dot[FIG_PLANE]  = trace_dot_plane;
	new->funcs.trace_normal[FIG_PLANE] = trace_normal_plane;
	new->funcs.trace_dot[FIG_SPHERE]  = trace_dot_sphere;
	new->funcs.trace_normal[FIG_SPHERE] = trace_normal_sphere;
	new->funcs.trace_dot[FIG_CYL] = trace_dot_cylinder;
	new->funcs.trace_normal[FIG_CYL] = trace_normal_cylinder;
	new->funcs.trace_dot[FIG_CONE] = trace_dot_cone;
	new->funcs.trace_normal[FIG_CONE] = trace_normal_cone;
	return (new);
}

void		rtv1_free(t_rt *rtv1)
{
	if (rtv1 == NULL)
		return ;
	scene_free(rtv1->scene);
	camera_free(rtv1->camera);
	window_free(rtv1->window);
	ft_free(rtv1);
}

void		rtv1_quit(t_rt *rtv1)
{
	rtv1_free(rtv1);
	SDL_Quit();
}
