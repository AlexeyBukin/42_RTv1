/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:05:29 by hush              #+#    #+#             */
/*   Updated: 2020/05/28 01:03:42 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define INFINITY_POSITIVE_RAW (0x7ff0000000000000)
# define INFINITY_NEGATIVE_RAW (0xfff0000000000000)

typedef struct		s_double3
{
	double 			x;
	double 			y;
	double 			z;
}					t_double3;

//todo make vector type
typedef t_double3	t_vec;
typedef t_double3	t_dot;

/*
** double3.c
*/

t_double3			d3_plus(t_double3 a, t_double3 b);
t_double3			d3_minus(t_double3 a, t_double3 b);
t_double3			d3_mult(t_double3 a, double b);
double				d3_dist_sqr(t_double3 a, t_double3 b);
double				d3_dist(t_double3 a, t_double3 b);

double			    vec_dot_product(t_double3 a, t_double3 b);
t_double3   		vec_cross_product(t_double3 a, t_double3 b);
t_double3			vec_normalize(t_double3 vec);
double				vec_len(t_double3 a);

char				*d3_to_str(t_double3 a);
char				*d3_to_str_color(t_double3 a);

t_vec				vec(double x, double y, double z);
double				vec_angle_cos(t_vec a, t_vec b);

#endif
