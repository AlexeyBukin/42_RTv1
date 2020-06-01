/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_s.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:29:54 by hush              #+#    #+#             */
/*   Updated: 2020/06/01 03:55:09 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_S_H
# define RT_SCENE_S_H

# include "rt_utils_s.h"
# include "rt_vector_s.h"

# define PBR_ROUGHNESS x
# define PBR_METALLIC  y
# define PBR_SPECULAR  x

typedef	struct	s_material
{
	long 			id;
	t_col			col;
	t_vec 			pbr;
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
	t_vec			cap;
	t_num 			r;
}				t_cone;

typedef	struct	s_cylinder
{
	t_vec			pos;
	t_vec			cap;
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

typedef struct		s_scene
{
	t_material		*materials;
	size_t			mat_num;
	t_figure		*figures;
	size_t			fig_num;
  	t_light			*lights;
	size_t			light_num;
}					t_scene;

#endif
