/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 00:26:47 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/17 22:16:54 by hush             ###   ########.fr       */
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

void		event_change_mode(t_rt *rtv1)
{
	if (rtv1->scene_active->cam_active == NULL || !(rtv1->keys.num != 0
	&& keys_pressed_now(&(rtv1->keys)) == 1 && rtv1->keys.m == TRUE))
		return ;
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
	else if (rtv1->keys.num == 8)
		rtv1->scene_active->cam_active->mode = TRACE_MODE_NORM_ANGLE;
	else
		return ;
	rtv1->flags.redraw = TRUE;
	ft_printf("changed color mode to %u\n", rtv1->keys.num);
}

void		rt_num_just_pressed(t_rt *rtv1)
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
			ft_printf("changed scene to %u\n", rtv1->keys.num);
		}
	}
	if (rtv1->keys.num != 0 && rtv1->keys.num - 1 < rtv1->scene_active->cam_num)
	{
		if (keys_pressed_now(&(rtv1->keys)) == 1 && rtv1->keys.c == TRUE)
		{
			rtv1->scene_active->cam_active =
				&(rtv1->scene_active->cameras[rtv1->keys.num - 1]);
			rtv1->flags.redraw = TRUE;
			ft_printf("changed camera to %u\n", rtv1->keys.num);
		}
	}
	if (rtv1->scenes != NULL && rtv1->scene_active != NULL)
		event_change_mode(rtv1);
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
