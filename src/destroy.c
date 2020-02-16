/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:49:47 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/16 20:50:04 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		destroy_window(t_window *win)
{
	if (win == NULL)
		return ;
	free(win->texture.img);
	SDL_DestroyWindow(win->sdl_window);
	SDL_DestroyTexture(win->sdl_texture);
	SDL_DestroyRenderer(win->sdl_renderer);
	free(win);
	return ;
}

void		destroy_rtv1(t_rtv1 *rtv1)
{
	if (rtv1 == NULL)
		return ;
	destroy_window(rtv1->window);
	free(rtv1);
}
