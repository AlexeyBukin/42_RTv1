/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:18:15 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 02:36:00 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
//
//int
//rt_add_scene(t_rt *rt, char *filename)
//{
//	int 	code;
//
//	rt->scenes = ft_realloc_arr(rt->scenes, rt->scene_num,
//								rt->scene_num, sizeof(t_scene));
//	if (rt->scenes == NULL)
//		return (ft_puterror(1,"Realloc scenes returned NULL"));
//
//	if (rt_read_scene(rt, source, &(scene->materials[scene->mat_num])) < 0)
//		return (ft_puterror(2, "Cannot read material"));
//
//
//	if (scene_from_file(r) < 0)
//		return (ft_puterror(2, "Cannot read figure"));
//	scene->fig_num++;
//	return (0);
//}

//todo scenes_from_file to *scenes
// todo ft_free() on return

t_rt		*rtv1_init(int ac, char **args)
{
	size_t		i;
	t_rt		*rtv1;

	if ((rtv1 = (t_rt*)ft_malloc(sizeof(t_rt))) == NULL)
		return (ft_puterr_null(1, "rtv1_init(): Cannot malloc rtv1"));
	rtv1->scene_num = 0;
	rtv1->scenes = NULL;

	if (ac  < 2)
	{
		if (rt_add_scene(rtv1, SCENE_DEFAULT) < 0)
			return (ft_puterr_null(2, "rtv1_init(): Cannot add scene"));
	}
	else
	{
		i = 1;
		while (i < (size_t) ac)
		{
			if ((rt_add_scene(rtv1, args[i])) < 0)
				return (ft_puterr_null(2, "rtv1_init(): Cannot add scene"));
			i++;
		}
	}

	rtv1->scene_active = &(rtv1->scenes[0]);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_puterr_null(4, "rtv1_init(): Cannot init SDL_VIDEO"));
	if ((rtv1->window = window_init(WIN_WIDTH, WIN_HEIGHT,
		rtv1->scenes[0].filename)) == NULL)
		return (ft_puterr_null(5, "rtv1_init(): Cannot init window"));
	if ((rtv1->camera = camera_init()) == NULL)
		return (ft_puterr_null(6, "rtv1_init(): Cannot init camera"));
	return (rtv1);
}

//todo active_scene_lol

void		rtv1_free(t_rt *rtv1)
{
	if (rtv1 == NULL)
		return ;
	scene_free(rtv1->scene_active);
	camera_free(rtv1->camera);
	window_free(rtv1->window);
	ft_free(rtv1);
}

void		rtv1_quit(t_rt *rtv1)
{
	rtv1_free(rtv1);
	SDL_Quit();
}
