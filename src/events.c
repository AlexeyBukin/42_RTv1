/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 00:26:47 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
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
	else if (scancode == SDL_SCANCODE_W)
	{
		rtv1->w = TRUE;
		ft_putendl("\'W\' pressed!");
	}
	else if (scancode == SDL_SCANCODE_A)
	{
		rtv1->a = TRUE;
		ft_putendl("\'A\' pressed!");
	}
	else if (scancode == SDL_SCANCODE_S)
	{
		rtv1->s = TRUE;
		ft_putendl("\'S\' pressed!");
	}
	else if (scancode == SDL_SCANCODE_D)
	{
		rtv1->d = TRUE;
		ft_putendl("\'D\' pressed!");
	}
	else if (scancode == SDL_SCANCODE_Q)
	{
		rtv1->q = TRUE;
		ft_putendl("\'Q\' pressed!");
	}
	else if (scancode == SDL_SCANCODE_E)
	{
		rtv1->e = TRUE;
		ft_putendl("\'E\' pressed!");
	}
	return (OK);
}

int		on_key_up(t_rtv1 *rtv1, SDL_Scancode scancode)
{
	if (scancode == SDL_SCANCODE_W)
	{
		rtv1->w = FALSE;
		ft_putendl("\'W\' released!");
	}
	if (scancode == SDL_SCANCODE_A)
	{
		rtv1->a = FALSE;
		ft_putendl("\'A\' released!");
	}
	else if (scancode == SDL_SCANCODE_S)
	{
		rtv1->s = FALSE;
		ft_putendl("\'S\' released!");
	}
	else if (scancode == SDL_SCANCODE_D)
	{
		rtv1->d = FALSE;
		ft_putendl("\'D\' released!");
	}
    else if (scancode == SDL_SCANCODE_Q)
    {
        rtv1->q = FALSE;
        ft_putendl("\'D\' released!");
    }
    else if (scancode == SDL_SCANCODE_E)
    {
        rtv1->e = FALSE;
        ft_putendl("\'D\' released!");
    }
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
