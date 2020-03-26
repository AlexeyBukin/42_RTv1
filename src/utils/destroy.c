/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:49:47 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		destroy_texture(t_texture *texture)
{
	if (texture == NULL)
		return ;
	free(texture->img);
	free(texture);
	return ;
}

void		destroy_window(t_window *win)
{
	if (win == NULL)
		return ;
	destroy_texture(win->texture);
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
