/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:14:45 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/02 17:28:13 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene		*scene_create()
{
	t_scene		*scene;

	if ((scene = (t_scene*)malloc(sizeof(t_scene))) == NULL)
		return (ft_puterr_null(1, "scene_create(): cannot malloc scene struct"));
	scene->figures = NULL;
	scene->fig_num = 0;
	return (scene);
}

int		scene_replace_figs(t_scene *scene, t_base_fig *figs_new)
{

	if (scene == NULL)
		return (ft_puterror(1, "scene_add_fig(): pointer scene is NULL"));
	if (figs_new == NULL && scene->fig_num != 0)
	{
		ft_putendl("warning: to clear the scene use scene_clear()");
	}
	free(scene->figures);
	scene->figures = figs_new;
	return (OK);
}
