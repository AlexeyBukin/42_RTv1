/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:59:24 by hush              #+#    #+#             */
/*   Updated: 2020/05/27 19:09:24 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"
# include "rt_utils.h"
# include "rt_vector.h"

typedef	struct	s_material
{
	long 			id;
	t_col			col;
	t_num 			roughness;
	t_num 			metallic;
	t_num 			specular;
}				t_material;

typedef	enum	e_figure_type
{
	FIG_PLANE,
	FIG_SPHERE,
	FIG_CONE,
	FIG_CYL
}				t_figure_type;

typedef	struct	s_plane
{
	t_vec			n;
	t_num			d;
}				t_plane;

typedef	struct	s_sphere
{
	t_vec			pos;
	t_num 			r;
}				t_sphere;


typedef	struct	s_cone
{
	t_vec			pos;
	t_vec			top;
	t_num 			r;
}				t_cone;

typedef	struct	s_cylinder
{
	t_vec			pos;
	t_vec			top;
	t_num 			r;
}				t_cylinder;

typedef	struct	s_figure
{
	t_material		*mat;
	t_figure_type	type;
	union
	{
		t_plane		plane;
		t_sphere	sphere;
		t_cylinder	cyl;
		t_cone		cone;
	};
}				t_figure;

typedef	struct	s_light
{
	t_vec			pos;
	t_col			col;
	t_num 			power;
}				t_light;

/*
** scene
*/

typedef struct		s_scene
{
	t_material		*materials;
	size_t			mat_num;
	t_figure		*figures;
	size_t			fig_num;
  	t_light			*lights;
	size_t			light_num;
}					t_scene;

t_scene				*scene_init();
void				scene_free(t_scene *scene);
char				*scene_to_str(t_scene *scene);

char				*figure_to_str(t_figure *fig);
char				*material_to_str(t_material *material);
char				*light_to_str(t_light *light);

#endif
