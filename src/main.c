/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:42:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/17 03:51:56 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			rtv1_init(t_rtv1 **rtv1)
{
	if (rtv1 == NULL)
		return (ft_puterror(1, "rtv1_init(): pointer is NULL"));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_puterror(2, "rtv1_init(): cannot init SDL_VIDEO"));
	if ((*rtv1 = (t_rtv1*)malloc(sizeof(t_rtv1))) == NULL)
		return (ft_puterror(3, "rtv1_init(): cannot malloc rtv1"));
	if (window_init(&((*rtv1)->window), WIN_WIDTH, WIN_HEIGHT) < 0)
		return (ft_puterror(4, "rtv1_init(): cannot init window"));
	texture_fill((*rtv1)->window->texture, color(0, 0, 0));
	if (camera_init_static(&((*rtv1)->camera)) < 0)
		return (ft_puterror(5, "rtv1_init(): cannot init camera"));
	return (0);
}

void		rtv1_quit(t_rtv1 *rtv1)
{
	if (rtv1 != NULL)
		destroy_rtv1(rtv1);
	SDL_Quit();
}

int			main(void)
{
	t_rtv1	*rtv1;

	rtv1 = NULL;
	if (rtv1_init(&rtv1) < 0)
	{
		rtv1_quit(rtv1);
		return (ft_puterror(1, "main(): problems running rtv1_init()"));
	}
	if (rtv1_loop(rtv1) < 0)
	{
		rtv1_quit(rtv1);
		return (ft_puterror(2, "main(): problems running rtv1_loop()"));
	}
	rtv1_quit(rtv1);
	return (0);
}
