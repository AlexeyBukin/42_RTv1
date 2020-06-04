/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 11:05:28 by hush              #+#    #+#             */
/*   Updated: 2020/06/02 02:15:19 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSER_H
# define RT_PARSER_H

# include "rt_scene.h"

# define KEYWORD_MATERIAL "material"
# define KEYWORD_LIGHT    "light"
# define KEYWORD_PLANE    "plane"
# define KEYWORD_CONE     "cone"
# define KEYWORD_CYLINDER "cylinder"
# define KEYWORD_SPHERE   "sphere"
# define KEYWORD_CAMERA   "camera"
# define SCENE_DEFAULT    "scenes/default.rts"

t_scene			*scene_from_file(char *filename);
t_num			read_num(char **source);
int				read_vec(char **source, t_vec *res);
t_bool			read_comma(char **str);
int				read_id(char **source, size_t *id_field);
int				mat_index(t_scene *scene, size_t id);
size_t			comments_skip_num(const char *str);
char			*comments_delete(char *str);
int				scene_add_figure(t_scene *s, char **src, t_figure_type t);
int				scene_add_material(t_scene *scene, char **source);
int				scene_add_light(t_scene *scene, char **source);
int				scene_add_camera(t_scene *scene, char **source);

#endif
