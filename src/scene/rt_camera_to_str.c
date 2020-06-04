/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 01:16:40 by hush              #+#    #+#             */
/*   Updated: 2020/06/03 21:39:22 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char				*camera_to_str(t_camera *camera)
{
	char 	*res;

	if (camera == NULL)
		return (ft_puterr_null(1, "camera_to_str(): NULL pointer"));
	res = ft_strdup("camera[");
	res = ft_strjoin_free(res, ft_lltoa(camera->id));
	res = ft_str_add(res, "]( pos:");
	res = ft_strjoin_free(res, vec_to_str_color(camera->pos));
	res = ft_str_add(res, ", dir:");
	res = ft_strjoin_free(res, vec_to_str_color(camera->dir));
	res = ft_str_add(res, ", dir_up:");
	res = ft_strjoin_free(res, vec_to_str_color(camera->dir_up));
	res = ft_str_add(res, ")");
	return (res);
}
