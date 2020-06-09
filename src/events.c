/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 00:26:47 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/06 17:34:32 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			keys_pressed_now(t_keys *keys)
{
	int		res;

	res = (keys->w + keys->a + keys->s + keys->d);
	res += (keys->q + keys->e + keys->r);
	res += (keys->m + keys->c + keys->f);
	return (res);
}

void 		rt_num_just_pressed(t_rt *rtv1)
{
	if (rtv1 == NULL)
		return ;
	if (rtv1->scenes == NULL || rtv1->scene_active == NULL)
		return ;
	if (rtv1->keys.num != 0 && rtv1->keys.num - 1 < rtv1->scene_num)
	{
		if (keys_pressed_now(&(rtv1->keys)) == 1 && rtv1->keys.f == TRUE)
		{
			rtv1->scene_active = &(rtv1->scenes[rtv1->keys.num - 1]);
			rtv1->flags.redraw = TRUE;
			ft_printf("changed scene\n");
		}
	}
	if (rtv1->scene_active->cameras == NULL)
		return ;
	if (rtv1->keys.num != 0 && rtv1->keys.num - 1 < rtv1->scene_active->cam_num)
	{
		if (keys_pressed_now(&(rtv1->keys)) == 1 && rtv1->keys.c == TRUE)
		{
			rtv1->scene_active->cam_active = &(rtv1->scene_active->cameras[rtv1->keys.num - 1]);
			rtv1->flags.redraw = TRUE;
			ft_printf("changed camera\n");
		}
	}
	if (rtv1->scene_active->cam_active == NULL)
		return ;
	if (rtv1->keys.num != 0 && keys_pressed_now(&(rtv1->keys)) == 1 && rtv1->keys.m == TRUE)
	{
		if (rtv1->keys.num == 1)
			rtv1->scene_active->cam_active->mode = TRACE_MODE_FULL;
		else if (rtv1->keys.num == 2)
			rtv1->scene_active->cam_active->mode = TRACE_MODE_NORMALS;
		else if (rtv1->keys.num == 3)
			rtv1->scene_active->cam_active->mode = TRACE_MODE_LIGHT;
		else if (rtv1->keys.num == 4)
			rtv1->scene_active->cam_active->mode = TRACE_MODE_COLOR;
		else if (rtv1->keys.num == 5)
			rtv1->scene_active->cam_active->mode = TRACE_MODE_DIST;
		else if (rtv1->keys.num == 6)
			rtv1->scene_active->cam_active->mode = TRACE_MODE_BRDF_G;
		else if (rtv1->keys.num == 7)
			rtv1->scene_active->cam_active->mode = TRACE_MODE_BRDF_D;
		else
			return ;
		rtv1->flags.redraw = TRUE;
		ft_printf("changed color mode\n");
	}
}

void		on_num_down(t_rt *rtv1, SDL_Scancode scancode)
{
	if (rtv1 == NULL)
		return ;
	rtv1->keys.num = 0;
	if (scancode == SDL_SCANCODE_1)
		rtv1->keys.num = 1;
	else if (scancode == SDL_SCANCODE_2)
		rtv1->keys.num = 2;
	else if (scancode == SDL_SCANCODE_3)
		rtv1->keys.num = 3;
	else if (scancode == SDL_SCANCODE_4)
		rtv1->keys.num = 4;
	else if (scancode == SDL_SCANCODE_5)
		rtv1->keys.num = 5;
	else if (scancode == SDL_SCANCODE_6)
		rtv1->keys.num = 6;
	else if (scancode == SDL_SCANCODE_7)
		rtv1->keys.num = 7;
	else if (scancode == SDL_SCANCODE_8)
		rtv1->keys.num = 8;
	else if (scancode == SDL_SCANCODE_9)
		rtv1->keys.num = 9;
	if (rtv1->keys.num != 0)
		rt_num_just_pressed(rtv1);
}

void		on_key_down(t_rt *rtv1, SDL_Scancode scancode)
{
	if (rtv1 == NULL)
		return ;
	else if (scancode == SDL_SCANCODE_ESCAPE)
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
	else if (scancode == SDL_SCANCODE_C)
		rtv1->keys.c = TRUE;
	else if (scancode == SDL_SCANCODE_F)
		rtv1->keys.f = TRUE;
//	else if (scancode == SDL_SCANCODE_X)
//		rtv1->keys.x = TRUE;
	else if (scancode == SDL_SCANCODE_M)
		rtv1->keys.m = TRUE;
	on_num_down(rtv1, scancode);
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
	else if (scancode == SDL_SCANCODE_C)
		rtv1->keys.c = FALSE;
	else if (scancode == SDL_SCANCODE_F)
		rtv1->keys.f = FALSE;
//	else if (scancode == SDL_SCANCODE_X)
//		rtv1->keys.x = FALSE;
	else if (scancode == SDL_SCANCODE_M)
		rtv1->keys.m = FALSE;
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
