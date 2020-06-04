/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_s.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:29:54 by hush              #+#    #+#             */
/*   Updated: 2020/06/03 22:13:32 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CAMERA_S_H
# define RT_CAMERA_S_H

typedef enum		e_camera_projection
{
	PROJECTION_ORTOGRAPHIC,
	PROJECTION_PERSPECTIVE
}					t_projection;

typedef enum		e_camera_color_mode
{
	COLOR_MODE_FULL_TRACE,
	COLOR_MODE_NORMALS,
	COLOR_MODE_LIGHT_AMOUNT,
	COLOR_MODE_COLOR_ONLY
}					t_color_mode;

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
	t_color_mode	mode;
}					t_camera;

#endif
