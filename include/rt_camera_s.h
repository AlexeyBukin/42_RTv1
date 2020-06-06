/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_s.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:29:54 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 03:15:47 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CAMERA_S_H
# define RT_CAMERA_S_H

#include "rt_s.h"
#include "rt_texture_s.h"
typedef enum		e_camera_projection
{
	PROJECTION_ORTOGRAPHIC,
	PROJECTION_PERSPECTIVE
}					t_projection;

typedef enum		e_trace_mode
{
	TRACE_MODE_FULL,
	TRACE_MODE_NORMALS,
	TRACE_MODE_LIGHT,
	TRACE_MODE_COLOR,
	TRACE_MODE_BRDF_G,
	TRACE_MODE_BRDF_D

}					t_trace_mode;

typedef struct		s_camera
{
	size_t 			id;
	t_vec			pos;
	t_vec			plane_pos;
	t_vec			dir;
	t_vec			dir_right;
	t_vec			dir_up;
	t_num 			size_x;
	t_num 			size_y;
	t_projection	projection;
	t_trace_mode	mode;
	t_texture		*texture;
}					t_camera;

#endif
