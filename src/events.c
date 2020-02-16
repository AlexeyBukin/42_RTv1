/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 00:26:47 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/17 01:03:00 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		on_key_down(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	(void)rtv1;
	if (scancode == SDL_SCANCODE_ESCAPE)
	{
		ft_putendl("Escape pressed!");
		return (EXIT);
	}
	return (OK);
}

int		on_key_up(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	(void)rtv1;
	(void)scancode;
	return (OK);
}

int		on_mouse_down(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	if (scancode == SDL_BUTTON_LEFT)
	{
		rtv1->LMB_down = TRUE;
		return (OK);
	}
	return (OK);
}

int		on_mouse_up(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	if (scancode == SDL_BUTTON_LEFT)
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
	{
		return (ft_puterror(2,
				"on_mouse_move(): rtv1->window pointer is NULL"));
	}
	if (rtv1->LMB_down == TRUE)
	{
		texture_put_pixel(rtv1->window->texture, color(255, 255, 255), x, y);
		return (RENDER);
	}
	return (OK);
}
