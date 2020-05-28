/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:33:57 by hush              #+#    #+#             */
/*   Updated: 2020/05/29 01:12:06 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "rt_struct.h"

t_col				rt_trace(t_rt *rtv1, t_ray ray);

t_num				trace_dot_cap(t_ray ray, t_ray plane_ray);
t_num				trace_dot_cone(t_ray ray, t_figure *fig);
t_num				trace_dot_cylinder(t_ray ray, t_figure *fig);
t_num				trace_dot_plane(t_ray ray, t_figure *fig);
t_num				trace_dot_sphere(t_ray ray, t_figure *fig);

t_vec				trace_normal_cone(t_ray ray, t_figure *fig);
t_vec				trace_normal_cylinder(t_ray ray, t_figure *fig);
t_vec				trace_normal_plane(t_ray ray, t_figure *fig);
t_vec				trace_normal_sphere(t_ray ray, t_figure *fig);

t_vec 				cylinder_intersect(t_ray ray, t_cylinder cyl, t_vec v);
t_vec 				cone_intersect(t_ray ray, t_cone cone, t_vec v);


#endif
