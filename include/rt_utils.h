/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 02:10:29 by hush              #+#    #+#             */
/*   Updated: 2020/06/01 15:15:41 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include "rt_utils_s.h"
# include "rt_vector_s.h"

# define COLOR_MAX 255
# define COLOR_MIN 0
# define ALPHA_MAX 255
# define ALPHA_MIN 0

/*
** color_1.c, color_2.c, ...
*/

t_col				col_add(t_col a, t_col b);
t_col				col_mask(t_col col, t_col mask);
t_col				col_from_int(int src);
int					col_to_int(t_col col);
t_col				col_from_normal(t_vec vector);

t_col				col_from_vec_norm(t_vec vector);
t_col				col_from_vec(t_vec vector);
t_col				col(t_byte red, t_byte green, t_byte blue);
t_col				col_alpha(t_byte r, t_byte g, t_byte b, t_byte a);
char				*col_to_str(t_col color);
char				*col_to_str_color(t_col color);

t_num				num_clamp(t_num val, t_num min, t_num max);
t_num 				num_sqr(t_num a);
int					num_cmp(t_num a, t_num b);
t_num				num_map(t_num num, t_vec from, t_vec to);

t_bool				ray_point_is_behind(t_ray ray, t_vec point);
t_ray				ray_inf();

#endif
