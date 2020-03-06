/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:23:16 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 05:57:11 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "SDL.h"
# include "scene.h"

# define COLOR_MAX 255
# define COLOR_MIN 0
# define ALPHA_MAX 255
# define ALPHA_MIN 0

# define WIN_WIDTH  640
# define WIN_HEIGHT 480

# define VEL_DELTA 0.2

# define RENDER_MAX_DIST 100.0
//
//# define WIN_WIDTH  100
//# define WIN_HEIGHT 100

typedef enum		e_result_code
{
	OK,
	EXIT,
	MOVE,
	RENDER,
	ERROR,
	UNSET
}					t_result_code;

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
	t_double3 		pos;
	t_double3		plane_pos;
	t_double3 		direction;
	t_double3 		direction_right;
	t_double3 		direction_up;
	double 			size_x;
	double 			size_y;
}					t_camera;

typedef struct		s_keys
{
	t_bool 			w;
	t_bool 			a;
	t_bool 			s;
	t_bool 			d;
}					t_keys;

typedef struct		s_rtv1
{
	t_window		*window;
	t_camera		camera;
	t_scene			*scene;
	double			vel_forward;
	double			vel_right;
	double			vel_up;
	t_bool			lmb_down;
	t_bool			trace;
	t_bool 			w;
	t_bool 			a;
	t_bool 			s;
	t_bool 			d;
	t_bool 			q;
	t_bool 			e;
}					t_rtv1;

/*
** events.c
*/

int					on_key_down(t_rtv1 *rtv1, SDL_Scancode scancode);
int					on_key_up(t_rtv1 *rtv1, SDL_Scancode scancode);
int					on_mouse_down(t_rtv1 *rtv1, SDL_Scancode scancode);
int					on_mouse_move(t_rtv1 *rtv1, int x, int y);
int					on_mouse_up(t_rtv1 *rtv1, SDL_Scancode scancode);

/*
** window.c
*/

int					window_init(t_window **win, size_t w, size_t h);
int					window_render(t_window *win);

/*
** destroy.c
*/

void				destroy_window(t_window *win);
void				destroy_rtv1(t_rtv1 *rtv1);

/*
** loop.c
*/

int					rtv1_loop(t_rtv1 *rtv1);
int					window_render(t_window *win);

/*
** texture.c
*/

t_texture			*texture_create(size_t w, size_t h);
int					texture_init(t_texture *texture, size_t w, size_t h);
void				texture_fill(t_texture *texture, t_color col);
void				texture_put_pixel(t_texture *texture, t_color col,
						size_t x, size_t y);

/*
** camera.c
*/

int					camera_move_global(t_camera *cam, t_vec dir);
int					camera_move_local(t_camera *cam, t_vec dir);
int					camera_init_static(t_camera *cam);

/*
** project.c
*/

int					project(t_rtv1 *rtv1);

/*
** main.c
*/
void				rtv1_quit(t_rtv1 *rtv1);

/*
** init.c
*/

int					rtv1_init(t_rtv1 **rtv1);
t_scene				*rtv1_scene(t_rtv1 *rtv1);
t_window			*rtv1_window(t_rtv1 *rtv1);
t_texture			*rtv1_window_texture(t_rtv1 *rtv1);
t_base_fig			**rtv1_scene_figs(t_rtv1 *rtv1);
t_light				**rtv1_scene_lights(t_rtv1 *rtv1);
t_base_fig			*rtv1_scene_fig_at(t_rtv1 *rtv1, size_t id);

/*
** scene.c
*/

t_scene				*scene_create(void);
int					scene_replace_figs(t_scene *scene, t_base_fig *figs_new);

/*
** trace.c
*/

t_color				trace(t_rtv1 *rtv1, t_ray ray);
//t_color				trace(t_rtv1 *rtv1, t_double3 from, t_double3 to);


/*
** infinity.c
*/

double		get_inf();
t_bool		is_inf(double d);
t_double3	d3_get_inf();
t_bool		d3_is_inf(t_double3 a);

/*
** figure.c
*/

t_base_fig			*fig_create(void);
int					fig_destroy(t_base_fig *fig);
t_base_fig			**fig_arr_create(size_t num);
int					fig_arr_destroy(t_base_fig **fig_arr);


/*
** cylinder.c
*/

t_double3			trace_cyl(t_double3 orig,
						t_double3 dir, t_base_fig *fig);
t_base_fig_cyl		*fig_cyl_create();

/*
** plane.c
*/

t_ray 				trace_plane_bounce(t_ray ray, t_base_fig *fig);
t_double3			trace_plane(t_double3 orig, t_vec dir, t_base_fig *pl);
t_base_fig_plane	*fig_plane_create(void);

/*
** sphere.c
*/

t_double3			trace_sphere(t_double3 orig, t_double3 dir,
  						t_base_fig *s);
t_base_fig_sphere	*fig_sphere_create(void);

/*
** utils.c
*/
double	clamp(double val, double min, double max);

/*
** lights.c
*/
t_light			**light_arr_create(size_t num);
#endif
