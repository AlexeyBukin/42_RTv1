/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:22:01 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 14:03:04 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_H
# define RT_SCENE_H

#include "rt_s.h"
#include "rt_scene_s.h"

# define SCENE_FILENAME_UNSET "Unset filename"

int					rt_add_scene(t_rt *rt, char *filename);
void 				scene_delete(t_scene *scene);
void				scene_free(t_scene *scene);

t_scene				*scene_init();
char				*scene_to_str(t_scene *scene);

char				*figure_to_str(t_figure *fig);
char				*material_to_str(t_material *material);
char				*light_to_str(t_light *light);
char				*camera_to_str(t_camera *camera);
void				material_set_default(t_material *mat);
//void				camera_set_default(t_camera	*cam);
//int					scene_camera_config(t_camera *cam);
int					scene_set_default(t_scene *scene);

#endif
