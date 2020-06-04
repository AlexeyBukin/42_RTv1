/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:13:19 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/04 11:34:48 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		check_input(t_rt *rtv1)
{
	ft_memset(&(rtv1->movement), '\0', sizeof(t_move));

	rtv1->movement.vel_local.x += (rtv1->keys.w) ? VEL_DELTA : 0;
	rtv1->movement.vel_local.x -= (rtv1->keys.s) ? VEL_DELTA : 0;

	rtv1->movement.vel_local.y += (rtv1->keys.d) ? VEL_DELTA : 0;
	rtv1->movement.vel_local.y -= (rtv1->keys.a) ? VEL_DELTA : 0;

	rtv1->movement.vel_local.z += (rtv1->keys.q) ? VEL_DELTA : 0;
	rtv1->movement.vel_local.z -= (rtv1->keys.e) ? VEL_DELTA : 0;

	if (!vec_is_zero(rtv1->movement.vel_local))
		rtv1->flags.is_moving = TRUE;
}

void		check_event(t_rt *rtv1, SDL_Event event)
{
	if (rtv1 == NULL)
		return ;
	if (event.type == SDL_QUIT)
		rtv1->flags.exit = TRUE;
	else if (event.type == SDL_KEYDOWN)
		on_key_down(rtv1, event.button.button);
	else if (event.type == SDL_KEYUP)
		on_key_up(rtv1, event.button.button);
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		on_mouse_down(rtv1, event.button.button);
	else if (event.type == SDL_MOUSEBUTTONUP)
		on_mouse_up(rtv1, event.button.button);
	else if (event.type == SDL_MOUSEMOTION)
		on_mouse_move(rtv1, event.motion.x, event.motion.y);
}

void	iterate_events(t_rt *rtv1)
{
	SDL_Event			event;

	if (rtv1 == NULL)
		return ;
	while (SDL_PollEvent(&event))
		check_event(rtv1, event);
	check_input(rtv1);
}

int		rt_redraw(t_rt *rtv1)
{
	if (rtv1 == NULL)
		return (ft_puterror(1, "redraw(): pointer rtv1 is NULL"));
	if (rtv1->window == NULL)
		return (ft_puterror(2, "redraw(): pointer rtv1->window is NULL"));
	texture_fill(rtv1->window->texture, col(0, 0, 0));
	if (project(rtv1) < 0)
		return (ft_puterror(3, "redraw(): Can't project()"));
	if (window_render(rtv1->window) < 0)
		return (ft_puterror(4, "redraw(): Can't window_render()"));
	return (0);
}

int		rt_loop(t_rt *rtv1)
{
	if (rtv1 == NULL)
		return (ft_puterror(1, "rtv1_loop(): pointer rtv1 is NULL"));
	if (rt_redraw(rtv1) < 0)
		return (ft_puterror(3, "rtv1_loop(): problem while redraw()"));
	while (TRUE)
	{
		ft_memset(&(rtv1->flags), '\0', sizeof(t_flags));
		iterate_events(rtv1);

		if (rtv1->flags.exit)
			break ;
		if (rtv1->flags.is_moving)
		{
			//TODO convert coords to global and move
			// create 't_vec  to_global(t_vec local_coords, t_vec local_x_vec);'
			// create 'void  move_global(t_vec *move_me, t_vec by_me);'
			camera_move_local(rtv1->scene_active->cameras, rtv1->movement.vel_local);
			rtv1->flags.redraw = TRUE;
		}
		if (rtv1->flags.redraw)
		{
			//ft_putendl("calling redraw...");
			if (rt_redraw(rtv1) < 0)
				return (ft_puterror(3, "rtv1_loop(): redraw()"));
		}
	}
	return (0);
}
