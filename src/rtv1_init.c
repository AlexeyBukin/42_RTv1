/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:36:18 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/03 21:30:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				rtv1_init(t_rtv1 **rtv1)
{
	t_rtv1		*new;

	if (rtv1 == NULL)
		return (ft_puterror(1, "rtv1_init(): pointer is NULL"));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_puterror(2, "rtv1_init(): cannot init SDL_VIDEO"));
	if ((new = (t_rtv1*)malloc(sizeof(t_rtv1))) == NULL)
		return (ft_puterror(3, "rtv1_init(): cannot malloc rtv1"));
	if (window_init(&(new->window), WIN_WIDTH, WIN_HEIGHT) < 0)
		return (ft_puterror(4, "rtv1_init(): cannot init window"));
	if (camera_init_static(&(new->camera)) < 0)
		return (ft_puterror(5, "rtv1_init(): cannot init camera"));
	new->vel_forward = 0;
	new->vel_right = 0;
	new->vel_up = 0;
	new->scene = scene_create();
	new->w = FALSE;
	new->a = FALSE;
	new->s = FALSE;
	new->d = FALSE;
	new->q = FALSE;
	new->e = FALSE;
	*rtv1 = new;
	return (0);
}

t_scene			*rtv1_scene(t_rtv1 *rtv1)
{
	if (rtv1 == NULL)
	{
		return (NULL);
	}
	return (rtv1->scene);
}

t_window		*rtv1_window(t_rtv1 *rtv1)
{
	if (rtv1 == NULL)
	{
		return (NULL);
	}
	return (rtv1->window);
}

t_base_fig**	rtv1_scene_figs(t_rtv1 *rtv1)
{
	if (rtv1 == NULL)
	{
		return (NULL);
	}
	if (rtv1->scene == NULL)
	{
		return (NULL);
	}
	return (rtv1->scene->figures);
}

t_point_light**	rtv1_scene_lights(t_rtv1 *rtv1)
{
	if (rtv1 == NULL)
	{
		return (NULL);
	}
	if (rtv1->scene == NULL)
	{
		return (NULL);
	}
	return (rtv1->scene->lights);
}