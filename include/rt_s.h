/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_s.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 02:09:58 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 21:07:21 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_S_H
# define RT_S_H

#include "SDL2/SDL.h"
#include "libft.h"
#include "rt_scene.h"
#include "rt_scene_s.h"
#include "rt_utils_s.h"
#include "rt_vector_s.h"
#include "rt_texture_s.h"

typedef struct		s_window
{
	SDL_Window		*sdl_window;
	SDL_Texture		*sdl_texture;
	SDL_Renderer	*sdl_renderer;
}					t_window;

typedef struct		s_keys
{
	t_bool 			w;
	t_bool 			a;
	t_bool 			s;
	t_bool 			d;
	t_bool 			q;
	t_bool 			e;
	t_bool 			r;
	t_bool 			lmb;
	t_bool 			rmb;
	t_bool 			mmb;
	int 			mouse_x;
	int 			mouse_y;
	size_t			num;
//	t_bool 			x;
	t_bool 			c;
	t_bool 			f;
	t_bool 			m;
}					t_keys;

typedef struct		s_move
{
	t_vec			vel_global;
	t_vec			vel_local;
}					t_move;

typedef struct		s_flags
{
	t_bool			log;
	t_bool			trace;
	t_bool			redraw;
	t_bool			is_moving;
	t_bool			exit;
}					t_flags;

typedef struct		s_rt
{
	t_window		*window;
	t_scene			*scenes;
	size_t			scene_num;
	t_scene			*scene_active;
	t_flags			flags;
	t_keys 			keys;
	t_move			movement;
}					t_rt;

#endif
