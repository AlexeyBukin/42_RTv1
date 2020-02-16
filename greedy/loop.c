/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:13:19 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/17 00:16:47 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		on_key_down(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	if(scancode == SDL_SCANCODE_ESCAPE)
	{
		ft_putendl("Escape pressed!");
		return (EXIT);
	}
	return (OK);
}

int		on_key_up(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	return (OK);
}

int		on_mouse_down(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	if(scancode == SDL_BUTTON_LEFT)
	{
		rtv1->LMB_down = TRUE;
		return (OK);
	}
	return (OK);
}

int		on_mouse_up(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	if(scancode == SDL_BUTTON_LEFT)
	{
		rtv1->LMB_down = FALSE;
		return (OK);
	}
	return (OK);
}

int		on_mouse_move(t_rtv1 *rtv1, int x, int y)
{
	if (rtv1 == NULL)
		return (ft_puterror(1, "on_mouse_move(): rtv1 pointer is NULL"));
	if (rtv1->window == NULL)
		return (ft_puterror(2, "on_mouse_move(): rtv1->window pointer is NULL"));
	if (rtv1.LMB_down == TRUE)
	{
		texture_put_pixel(rtv1->window->texture, color(255, 255, 255), x, y);
		return (RENDER);
	}
	return (OK);
}

int		iterate_events(t_rtv1 *rtv1)
{
	SDL_Event			event;
	t_bool				render_needed;
	int					result_code;

	render_needed = FALSE;
	while(SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			return (EXIT);
		else if (event.type == SDL_KEYDOWN)
			result_code = on_key_down(rtv1, event.button.button);
		else if (event.type == SDL_KEYUP)
			result_code = on_key_up(rtv1, event.button.button);
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			result_code = on_mouse_down(rtv1, event.button.button);
		else if (event.type == SDL_MOUSEBUTTONUP)
			result_code = on_mouse_up(rtv1, event.button.button);
		else if (event.type == SDL_MOUSEMOTION)
			result_code = on_mouse_move(rtv1, event.motion.x, event.motion.y);
		if (result_code == EXIT)
			return (EXIT);
		else if (result_code == RENDER)
			render_needed = TRUE;
	}
	if (render_needed == TRUE)
		return (RENDER);
	return (OK);
}

int		rtv1_loop(t_rtv1 *rtv1)
{
	int				result_code;

	texture_fill(rtv1->window->texture, color(0, 0, 0));
	if(window_render(rtv1->window) < 0)
		return (ft_puterror(1, "rtv1_loop(): problem running render_window()"));
	while(TRUE)
	{
		result_code = iterate_events(rtv1);
		if (result_code == EXIT)
			return (EXIT);
		else if (result_code == RENDER)
		{
			window_render(rtv1->window);
			//stuff to render
		}
	}
	return (0);
}


//int		rtv1_loop(t_rtv1 *rtv1)
//{
//	texture_fill(rtv1->window->texture, get_color(0, 0, 0));
//	render_window(rtv1->window);
//
//	SDL_Event event;
//	t_bool running = TRUE;
//	t_bool LMB_down = FALSE;
//
//	Uint64 freq = SDL_GetPerformanceFrequency();
//
//	while(running == TRUE)
//	{
//		Uint64 start = SDL_GetPerformanceCounter();
//		while( SDL_PollEvent( &event ) )
//		{
//			if (event.type == SDL_QUIT)
//			{
//				running = FALSE;
//			}
//			else if (event.type == SDL_KEYDOWN)
//			{
//				if (event.button.button == SDL_SCANCODE_ESCAPE)
//					running = FALSE;
//				break ;
//			}
//			else if (event.type == SDL_MOUSEBUTTONUP)
//			{
//				if (event.button.button == SDL_BUTTON_LEFT)
//					LMB_down = FALSE;
//				break ;
//			}
//			else if (event.type == SDL_MOUSEBUTTONDOWN)
//			{
//				if (event.button.button == SDL_BUTTON_LEFT)
//					LMB_down = TRUE;
//				break ;
//			}
//			else if (event.type == SDL_MOUSEMOTION)
//			{
//				if (LMB_down)
//				{
////					texture_put_pixel(c_w, get_opaque_color(255, 255, 255), event.motion.x, event.motion.y);
////					texture_put_pixel(c_w_a, get_opaque_color(255, 255, 255), event.motion.x, event.motion.y);
//
//					render_window(rtv1->window);
//				}
//				break;
//			}
//		}
//
//		Uint64 end = SDL_GetPerformanceCounter();
//		double seconds = ( end - start ) / (double)( freq );
//		char * s = ft_itoa(round(seconds * 1000.0));
//		ft_putendl(s);
//		free(s);
//	}
//	return (0);
//}
