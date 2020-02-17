/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:48:52 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/17 05:09:05 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** FOV = 90 degrees
*/

int			camera_init_static(t_camera *cam)
{
	if (cam == NULL)
		return (ft_puterror(1, "camera_init_static(): cam pointer is NULL"));
	(*cam).pos = (t_double3) {0.0, 0.0, 1.8};
	(*cam).direction = (t_double3) {0.0, 1.0, 0.0};
	(*cam).plane_pos = (t_double3) {0.0, (double)WIN_WIDTH / 10000 / 2, 1.8};
	(*cam).size_x = (double)WIN_WIDTH / 10000;
	(*cam).size_y = (double)WIN_HEIGHT / 10000;
	(*cam).direction_x = (t_double3) {1.0, 0.0, 0.0};
	(*cam).direction_y = (t_double3) {0.0, 0.0, 1.0};
	return (0);
}
