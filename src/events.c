/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 00:26:47 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/28 01:03:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		on_key_down(t_rt *rtv1, SDL_Scancode scancode)
{
	if (rtv1 == NULL)
		return ;
	if (scancode == SDL_SCANCODE_ESCAPE)
		rtv1->flags.exit = TRUE;
	else if (scancode == SDL_SCANCODE_R)
		rtv1->keys.r = TRUE;
	else if (scancode == SDL_SCANCODE_W)
		rtv1->keys.w = TRUE;
	else if (scancode == SDL_SCANCODE_A)
		rtv1->keys.a = TRUE;
	else if (scancode == SDL_SCANCODE_S)
		rtv1->keys.s = TRUE;
	else if (scancode == SDL_SCANCODE_D)
		rtv1->keys.d = TRUE;
	else if (scancode == SDL_SCANCODE_Q)
		rtv1->keys.q = TRUE;
	else if (scancode == SDL_SCANCODE_E)
		rtv1->keys.e = TRUE;
}

void		on_key_up(t_rt *rtv1, SDL_Scancode scancode)
{
	if (rtv1 == NULL)
		return ;
	if (scancode == SDL_SCANCODE_R)
		rtv1->keys.r = FALSE;
	else if (scancode == SDL_SCANCODE_W)
		rtv1->keys.w = FALSE;
	else if (scancode == SDL_SCANCODE_A)
		rtv1->keys.a = FALSE;
	else if (scancode == SDL_SCANCODE_S)
		rtv1->keys.s = FALSE;
	else if (scancode == SDL_SCANCODE_D)
		rtv1->keys.d = FALSE;
	else if (scancode == SDL_SCANCODE_Q)
		rtv1->keys.q = FALSE;
	else if (scancode == SDL_SCANCODE_E)
		rtv1->keys.e = FALSE;
}


void		on_mouse_down(t_rt *rtv1, SDL_Scancode scancode)
{
	if (rtv1 == NULL)
		return ;
	if (scancode == SDL_BUTTON_LEFT)
	{
		rtv1->keys.lmb = TRUE;
	}
	else if (scancode == SDL_BUTTON_RIGHT)
	{
		rtv1->keys.rmb = TRUE;
	}
	else if (scancode == SDL_BUTTON_MIDDLE)
	{
		rtv1->keys.rmb = TRUE;
	}
}

void		on_mouse_up(t_rt *rtv1, SDL_Scancode scancode)
{
	if (rtv1 == NULL)
		return ;
	if (scancode == SDL_BUTTON_LEFT)
	{
		rtv1->keys.lmb = FALSE;
	}
	else if (scancode == SDL_BUTTON_RIGHT)
	{
		rtv1->keys.rmb = FALSE;
	}
	else if (scancode == SDL_BUTTON_MIDDLE)
	{
		rtv1->keys.mmb = FALSE;
	}
}

void		on_mouse_move(t_rt *rtv1, int x, int y)
{
	if (rtv1 == NULL)
		return ;
	if (rtv1->window == NULL)
	{
		ft_puterror(2,
					"on_mouse_move(): rtv1->window pointer is NULL");
		return ;
	}
	rtv1->keys.mouse_x = x;
	rtv1->keys.mouse_y = y;
}
