/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:13:19 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/17 01:01:56 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		iterate_events(t_rtv1 *rtv1)
{
	SDL_Event			event;
	t_bool				render_needed;
	int					result_code;

	render_needed = FALSE;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
			result_code = on_key_down(rtv1, event.button.button);
		else if (event.type == SDL_KEYUP)
			result_code = on_key_up(rtv1, event.button.button);
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			result_code = on_mouse_down(rtv1, event.button.button);
		else if (event.type == SDL_MOUSEBUTTONUP)
			result_code = on_mouse_up(rtv1, event.button.button);
		else if (event.type == SDL_MOUSEMOTION)
			result_code = on_mouse_move(rtv1, event.motion.x, event.motion.y);
		if (event.type == SDL_QUIT || result_code == EXIT)
			return (EXIT);
		render_needed = result_code == RENDER ? TRUE : FALSE;
	}
	if (render_needed == TRUE)
		return (RENDER);
	return (OK);
}

int		rtv1_loop(t_rtv1 *rtv1)
{
	int				result_code;

	if (window_render(rtv1->window) < 0)
		return (ft_puterror(1, "rtv1_loop(): problem running render_window()"));
	while (TRUE)
	{
		result_code = iterate_events(rtv1);
		if (result_code < 0)
		{
			return (ft_puterror(2,
					"rtv1_loop(): problem running iterate_events()"));
		}
		else if (result_code == EXIT)
		{
			return (EXIT);
		}
		else if (result_code == RENDER)
		{
			window_render(rtv1->window);
		}
	}
	return (0);
}
