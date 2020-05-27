/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:23:16 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/27 16:03:25 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "SDL2/SDL.h"
# include "rt_scene.h"
# include "libft.h"
# include "rt_utils.h"
# include "rt_vector.h"
# include "rt_parser.h"
# include "rt_trace.h"
# include "rt_struct.h"

# define WIN_WIDTH  640
# define WIN_HEIGHT 480

# define VEL_DELTA 0.2

# define EPSILON   0.0001

/*
** events.c
*/

void				on_key_down(t_rt *rtv1, SDL_Scancode scancode);
void				on_key_up(t_rt *rtv1, SDL_Scancode scancode);
void				on_mouse_down(t_rt *rtv1, SDL_Scancode scancode);
void				on_mouse_move(t_rt *rtv1, int x, int y);
void				on_mouse_up(t_rt *rtv1, SDL_Scancode scancode);

/*
** window.c
*/

void				window_free(t_window *win);
t_window			*window_init(size_t w, size_t h, const char *name);
int					window_render(t_window *win);

/*
** destroy.c
*/

void				destroy_window(t_window *win);
void				destroy_rtv1(t_rt *rtv1);

/*
** loop.c
*/

int					rt_loop(t_rt *rtv1);
int					window_render(t_window *win);

/*
** texture.c
*/

void				texture_free(t_texture *texture);
t_texture			*texture_init(size_t w, size_t h);
void				texture_fill(t_texture *texture, t_col col);
void				texture_put_pixel(t_texture *texture, t_col col,
						size_t x, size_t y);

/*
** camera.c
*/

t_camera			*camera_init();
void				camera_free(t_camera *cam);
int					camera_move_global(t_camera *cam, t_vec dir);
int					camera_move_local(t_camera *cam, t_vec dir);
int					camera_init_static(t_camera *cam);

/*
** project.c
*/

int					project(t_rt *rtv1);

/*
** main.c
*/
void				rtv1_quit(t_rt *rtv1);

/*
** init.c
*/

t_rt				*rtv1_init(int ac, char **args);
t_scene				*rtv1_scene(t_rt *rtv1);
t_window			*rtv1_window(t_rt *rtv1);
t_texture			*rtv1_window_texture(t_rt *rtv1);

#endif
