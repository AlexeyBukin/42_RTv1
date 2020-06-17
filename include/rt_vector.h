/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:24:51 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 21:24:05 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_VECTOR_H
# define RT_VECTOR_H

# include <math.h>
# include "rt_vector_s.h"

/*
** vector_1.c
*/

t_vec				vec_plus(t_vec a, t_vec b);
t_vec				vec_minus(t_vec a, t_vec b);
t_vec				vec_mult(t_vec a, t_vec b);
t_vec				vec_div(t_vec a, t_vec b);
t_vec				vec_sqr(t_vec a);

/*
** vector_2.c
*/

t_vec				vec_plus_num(t_vec v, t_num n);
t_vec				vec_minus_num(t_vec v, t_num n);
t_vec				vec_mult_num(t_vec v, t_num n);
t_vec				vec_div_num(t_vec v, t_num n);
t_num				vec_sum(t_vec v);

/*
** vector_3.c
*/

t_vec				vec(t_num x, t_num y, t_num z);
t_vec				vec_zero();
t_bool				vec_is_zero(t_vec a);
t_vec				vec_inf();
t_bool				vec_is_inf(t_vec a);

/*
** vector_4.c
*/

t_vec				vec_invert(t_vec vector);
t_vec				vec_normalize(t_vec vec);
t_num				vec_dot(t_vec a, t_vec b);
t_vec				vec_cross(t_vec a, t_vec b);
t_num				vec_angle_cos(t_vec a, t_vec b);

/*
** vector_5.c
*/

t_num				vec_dist_sqr(t_vec a, t_vec b);
t_num				vec_dist(t_vec a, t_vec b);
t_num				vec_len(t_vec a);
t_vec				vec_max(t_vec a, t_vec b);
t_vec				vec_min(t_vec a, t_vec b);

/*
** vector_6.c
*/

t_vec				vec_do_vec(t_vec v1, t_vec v2, t_num f(t_num n1, t_num n2));
t_vec				vec_do_num(t_vec v, t_num n, t_num f(t_num n1, t_num n2));
t_vec				vec_from_color(t_col c);
char				*vec_to_str(t_vec a);
char				*vec_to_str_color(t_vec a);

/*
** vector_7.c
*/

t_bool				vec_point_is_behind(t_vec vec_from_zero, t_vec point);
t_vec				vec_clamp(t_vec source, t_num min, t_num max);
t_vec				vec_max_num(t_vec v, t_num n);
t_vec				vec_max_min(t_vec v, t_num n);

/*
** vector_8.c
*/

t_vec				vec_to_srgb(t_vec v);

#endif
