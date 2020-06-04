/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:14:51 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 15:54:05 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CAMERA_H
# define RT_CAMERA_H

int				camera_config(t_camera *cam);
void			camera_set_default(t_camera	*cam);
void 			camera_delete(t_camera *cam);
void			camera_free(t_camera *cam);


#endif
