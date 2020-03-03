/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:59:24 by hush              #+#    #+#             */
/*   Updated: 2020/03/04 01:14:27 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"
# include "color.h"
# include "vector.h"

/*
** basic scene block
*/

typedef enum		e_figure_type
{
	FIG_PLANE,
	FIG_SPHERE,
	FIG_CONE,
	FIG_CYLINDER,
	FIG_TYPES_NUM
}					t_figure_type;

typedef	struct	s_base_fig_plane
{
	t_figure_type	type;
	t_double3		pos;
	t_color			col;
	t_double3		a;
	t_double3		b;
}				t_base_fig_plane;

typedef	struct	s_base_fig_sphere
{
	t_figure_type	type;
	t_double3		pos;
	t_color			col;
	double 			r;
}				t_base_fig_sphere;

typedef	struct	s_base_fig_cone
{
	t_figure_type	type;
	t_double3		pos;
	t_color			col;
	t_double3		top;
	double 			r;
}				t_base_fig_cone;

typedef	struct	s_base_fig_cyl
{
	t_figure_type	type;
	t_double3		pos;
	t_color			col;
	t_double3		top;
	double 			r;
}				t_base_fig_cyl;

typedef	struct	s_figure_base
{
	t_figure_type	type;
	t_double3		pos;
	t_color			col;
}				t_figure_base;

typedef	union	s_base_fig
{
	t_figure_base		base;
	t_base_fig_plane	plane;
	t_base_fig_sphere	sphere;
	t_base_fig_cyl		cyl;
	t_base_fig_cone		cone;
}				t_base_fig;

/*
** light block
*/

typedef enum		e_falloff
{
	FALLOFF_LINEAR,
	FALLOFF_QUADRATIC,
}					t_falloff;

typedef	struct	t_point_light
{
	t_double3		pos;
	t_color			col;
	double 			power;
	t_falloff		type;
	double 			falloff;
}				t_point_light;

typedef	union	s_light
{
	t_point_light		point;
}				t_light;

/*
** scene
*/

typedef struct		s_scene
{
	t_base_fig		**figures;
	t_point_light	**lights;
}					t_scene;

#endif
