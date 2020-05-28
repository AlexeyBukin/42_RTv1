/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 11:05:28 by hush              #+#    #+#             */
/*   Updated: 2020/05/24 11:05:28 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "rt_scene.h"

# define KEYWORD_MATERIAL "material"
# define KEYWORD_LIGHT    "light"
# define KEYWORD_PLANE    "plane"
# define KEYWORD_CONE     "cone"
# define KEYWORD_CYLINDER "cylinder"
# define KEYWORD_SPHERE   "sphere"
# define SCENE_DEFAULT    "scenes/default.rts"

t_scene			*scene_from_file(char *filename);
t_num			read_num(char **source);
int				read_vec(char **source, t_vec *res);
t_bool			read_comma(char **str);
long			read_id(char **source);
int				mat_index(t_scene *scene, long id);
size_t			comments_skip_num(const char *str);
void			comments_delete(char *str);
int				scene_add_figure(t_scene *s, char **src, t_figure_type t);
int				scene_add_material(t_scene *scene, char **source);
int				scene_add_light(t_scene *scene, char **source);

#endif
