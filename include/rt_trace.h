/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 02:10:15 by hush              #+#    #+#             */
/*   Updated: 2020/06/15 16:35:35 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TRACE_H
# define RT_TRACE_H

# include "rt_s.h"



t_vec				fresnel_schlick(t_vec f0, t_num cos_theta);
t_col				rt_trace_brdf_g(t_scene *scene, t_ray ray);
t_col				rt_trace_brdf_d(t_scene *scene, t_ray ray);
t_num				brdf_get_d(t_vec n, t_vec v, t_vec l, t_material *mat);
t_num				brdf_get_g(t_vec n, t_vec v, t_vec l, t_material *mat);

/*
** rt_trace.c
*/

t_col				rt_trace(t_scene *scene, t_ray ray, t_trace_mode mode);
t_figure			*rt_trace_nearest(t_scene *scene, t_ray ray);
t_figure			*rt_trace_nearest_dist(t_scene *scene, t_ray ray, t_num *dist);
t_num				trace_dot_fig(t_ray ray, t_figure *fig);
t_vec				trace_normal_fig(t_ray ray, t_figure *fig);

/*
** rt_trace_modes.c
*/

t_col				rt_trace_mode_ggx(t_scene *scene, t_ray ray);
t_col				rt_trace_mode_normals(t_scene *scene, t_ray ray);
t_col				rt_trace_mode_normals_angle(t_scene *scene, t_ray ray);
t_col				rt_trace_mode_color_only(t_scene *scene, t_ray ray);
t_col				rt_trace_mode_light(t_scene *scene, t_ray ray);
t_col				rt_trace_mode_dist(t_scene *scene, t_ray ray);

/*
** rt_trace_dot_cone.c, rt_trace_normal_cone.c, ...
*/

t_num				trace_dot_cap(t_ray ray, t_ray plane_ray);
t_num				trace_dot_cone(t_ray ray, t_figure *fig);
t_num				trace_dot_cylinder(t_ray ray, t_figure *fig);
t_num				trace_dot_plane(t_ray ray, t_figure *fig);
t_num				trace_dot_sphere(t_ray ray, t_figure *fig);

t_vec				trace_normal_cone(t_ray ray_in, t_figure *fig);
t_vec				trace_normal_cylinder(t_ray ray, t_figure *fig);
t_vec				trace_normal_plane(t_ray ray, t_figure *fig);
t_vec				trace_normal_sphere(t_ray ray, t_figure *fig);

t_vec 				cylinder_intersect(t_ray ray, t_cylinder cyl, t_vec v);
t_vec 				cone_intersect(t_ray ray, t_cone cone, t_vec v);


/*
** ggx.c
*/

t_num				ggx_distribution(t_num cosThetaNH, t_num alpha);
t_num				ggx_partial_geometry(t_num cos_theta_n, t_num alpha);

/*
** schlick.c
*/

t_vec				fresnel_schlick(t_vec f0, t_num cos_theta);

#endif
