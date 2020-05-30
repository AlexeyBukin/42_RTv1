/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:42:52 by hush              #+#    #+#             */
/*   Updated: 2020/05/29 21:15:57 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

# include "SDL2/SDL.h"
# include "libft.h"

typedef struct		s_texture
{
	size_t			size_x;
	size_t			size_y;
	t_byte			*img;
}					t_texture;

typedef struct		s_window
{
	t_texture		*texture;
	SDL_Window		*sdl_window;
	SDL_Texture		*sdl_texture;
	SDL_Renderer	*sdl_renderer;
}					t_window;

/*
** basic scene block
*/

typedef struct		s_camera
{
	t_vec			pos;
	t_vec			plane_pos;
	t_vec			direction;
	t_vec 			direction_right;
	t_vec 			direction_up;
	t_num 			size_x;
	t_num 			size_y;
}					t_camera;

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

typedef struct		s_functions
{
	t_num			(*trace_dot[4])(t_ray ray, t_figure *fig);
	t_vec			(*trace_normal[4])(t_ray ray, t_figure *fig);
}					t_functions;


typedef struct		s_rt
{
	t_window		*window;
	t_camera		*camera;
	t_scene			*scene;
	t_flags			flags;
	t_keys 			keys;
	t_move			movement;
	t_functions		funcs;
}					t_rt;

#endif
