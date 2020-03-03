/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 00:26:47 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/03 15:44:46 by kcharla          ###   ########.fr       */
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
	else if (scancode == SDL_SCANCODE_R)
	{
		ft_putendl("\'R\' pressed!");
		return (RENDER);
	}
	else if (scancode == SDL_SCANCODE_A)
	{
		if (rtv1->vel_right != 0)
			rtv1->vel_right = 0;
		else
			rtv1->vel_right = -0.1;
		ft_putendl("\'A\' pressed!");
		return (RENDER);
	}
	else if (scancode == SDL_SCANCODE_D)
	{
		if (rtv1->vel_right != 0)
			rtv1->vel_right = 0;
		else
			rtv1->vel_right = 0.1;
		ft_putendl("\'D\' pressed!");
		return (RENDER);
	}
	else if (scancode == SDL_SCANCODE_Q)
	{
		if (rtv1->vel_up != 0)
			rtv1->vel_up = 0;
		else
			rtv1->vel_up = 0.1;
		ft_putendl("\'Q\' pressed!");
		return (RENDER);
	}
	else if (scancode == SDL_SCANCODE_E)
	{
		if (rtv1->vel_up != 0)
			rtv1->vel_up = 0;
		else
			rtv1->vel_up = -0.1;
		ft_putendl("\'E\' pressed!");
		return (RENDER);
	}
	else if (scancode == SDL_SCANCODE_W)
	{
		if (rtv1->vel_forward != 0)
			rtv1->vel_forward = 0;
		else
			rtv1->vel_forward = 0.1;
		ft_putendl("\'W\' pressed!");
		return (RENDER);
	}
	else if (scancode == SDL_SCANCODE_S)
	{
		if (rtv1->vel_forward != 0)
			rtv1->vel_forward = 0;
		else
			rtv1->vel_forward = -0.1;
		ft_putendl("\'S\' pressed!");
		return (RENDER);
	}
	return (OK);
}

int		on_key_up(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	if (scancode == SDL_SCANCODE_A || scancode == SDL_SCANCODE_D)
	{
		rtv1->vel_right = 0;
		ft_putendl("\'A_D\' released!");
		return (RENDER);
	}
	if (scancode == SDL_SCANCODE_Q || scancode == SDL_SCANCODE_E)
	{
		rtv1->vel_up = 0;
		ft_putendl("\'Q_E\' released!");
		return (RENDER);
	}
	if (scancode == SDL_SCANCODE_W || scancode == SDL_SCANCODE_S)
	{
		rtv1->vel_forward = 0;
		ft_putendl("\'W_S\' released!");
		return (RENDER);
	}

	(void)rtv1;
	(void)scancode;
	return (OK);
}

int		on_mouse_down(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	if (scancode == SDL_BUTTON_LEFT)
	{
		rtv1->lmb_down = TRUE;
		return (OK);
	}
	return (OK);
}

int		on_mouse_up(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	if (scancode == SDL_BUTTON_LEFT)
	{
		rtv1->lmb_down = FALSE;
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
	(void)x;
	(void)y;
	return (OK);
}
