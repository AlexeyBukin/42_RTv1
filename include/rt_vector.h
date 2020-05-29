/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:24:51 by hush              #+#    #+#             */
/*   Updated: 2020/05/29 13:47:53 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include <math.h>

/*
** typedef double		t_num;
** typedef float		t_num;
*/

typedef double		t_num;

typedef struct		s_vec
{
	t_num 			x;
	t_num 			y;
	t_num 			z;
}					t_vec;

typedef	struct		s_ray
{
	t_vec			pos;
	t_vec			dir;
}					t_ray;

/*
** vector_1.c vector_2.c ...
*/

t_vec				vec_plus(t_vec a, t_vec b);
t_vec				vec_minus(t_vec a, t_vec b);
t_vec				vec_mult(t_vec a, t_num b);
t_num				vec_dist_sqr(t_vec a, t_vec b);
t_num				vec_dist(t_vec a, t_vec b);

t_num			    vec_dot_product(t_vec a, t_vec b);
t_num				vec_angle_cos(t_vec a, t_vec b);
t_vec   			vec_cross_product(t_vec a, t_vec b);
t_num				vec_len(t_vec a);
t_vec				vec_normalize(t_vec vec);

t_vec				vec(t_num x, t_num y, t_num z);
char				*vec_to_str(t_vec a);
char				*vec_to_str_color(t_vec a);
t_bool				vec_isinf(t_vec a);
t_vec				vec_inf();

int					vec_cmp_len(t_vec a, t_vec b);
t_vec				vec_zero();
t_bool				vec_is_zero(t_vec a);
t_bool				vec_point_is_behind(t_vec vec_from_zero, t_vec point);
t_vec				vec_invert(t_vec vector);

#endif
