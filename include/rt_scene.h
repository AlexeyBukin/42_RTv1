/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:22:01 by hush              #+#    #+#             */
/*   Updated: 2020/05/30 16:22:01 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_H
# define RT_SCENE_H

# include "rt_scene_s.h"

t_scene				*scene_init();
void				scene_free(t_scene *scene);
char				*scene_to_str(t_scene *scene);

char				*figure_to_str(t_figure *fig);
char				*material_to_str(t_material *material);
char				*light_to_str(t_light *light);
char				*camera_to_str(t_camera *camera);

#endif
