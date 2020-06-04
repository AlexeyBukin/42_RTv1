/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:18:15 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 16:13:39 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
		ft_strdup(rtv1->scenes[0].filename))) == NULL)
		return (ft_puterr_null(5, "rtv1_init(): Cannot init window"));
	return (rtv1);
}

void 	rt_scene_arr_free(t_rt *rtv1)
{
	size_t		i;

	if (rtv1 == NULL)
		return ;
	i = 0;
	while (i < rtv1->scene_num)
	{
		scene_delete(&(rtv1->scenes[i]));
		i++;
	}
	ft_free(rtv1->scenes);
}

void		rtv1_free(t_rt *rtv1)
{
	if (rtv1 == NULL)
		return ;
	rt_scene_arr_free(rtv1);
	//window_free(rtv1->window);
	ft_free(rtv1);
}

//todo active_scene_lol

void		rtv1_quit(t_rt *rtv1)
{
	rtv1_free(rtv1);
	SDL_Quit();
}
