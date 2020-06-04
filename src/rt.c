/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:18:15 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 16:42:43 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int 		rt_scene_arr_read(t_rt *rt, size_t ac, char **av)
{
	size_t		i;

	if (rt == NULL || av == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	rt->scene_num = 0;
	rt->scenes = NULL;
	if (ac < 2)
	{
		if (rt_add_scene(rt, SCENE_DEFAULT) < 0)
			return (ft_puterror(2, "Cannot add default scene"));
	}
	else
	{
		i = 1;
		while (i < (size_t) ac)
		{
			if ((rt_add_scene(rt, av[i])) < 0)
				return (ft_puterror(3, "Cannot add scene"));
			i++;
		}
	}
	return (0);
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

// todo ft_free() on return

t_rt		*rt_new(int ac, char **args)
{
	t_rt		*rt;

	if ((rt = (t_rt*)ft_malloc(sizeof(t_rt))) == NULL)
		return (ft_puterr_null(1, "rtv1_new(): Cannot malloc rtv1"));
	if (rt_scene_arr_read(rt, ac, args) < 0)
	{
		ft_free(rt);
		return (ft_puterr_null(2, "rtv1_new(): Cannot read scenes array"));
	}
	rt->scene_active = &(rt->scenes[0]);
	if ((rt->window = window_init(WIN_WIDTH, WIN_HEIGHT,
		rt->scenes[0].filename)) == NULL)
	{
		rt_scene_arr_free(rt);
		ft_free(rt);
		return (ft_puterr_null(3, "rtv1_new(): Cannot init window"));
	}

	return (rt);
}

void		rtv1_free(t_rt *rtv1)
{
	if (rtv1 == NULL)
		return ;
	rt_scene_arr_free(rtv1);
	window_free(rtv1->window);
	ft_free(rtv1);
}

void		rt_quit(t_rt *rtv1)
{
	rtv1_free(rtv1);
	SDL_Quit();
}
