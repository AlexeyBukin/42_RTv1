/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_s.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:29:54 by hush              #+#    #+#             */
/*   Updated: 2020/06/02 01:25:11 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CAMERA_S_H
# define RT_CAMERA_S_H

typedef struct		s_camera
{
	long 			id;
	t_vec			pos;
	t_vec			plane_pos;
	t_vec			direction;
	t_vec 			direction_right;
	t_vec 			direction_up;
	t_num 			size_x;
	t_num 			size_y;
}					t_camera;

#endif
