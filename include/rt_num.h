/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_num.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:28:19 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 20:21:28 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_NUM_H
# define RT_NUM_H

# include "rt_vector_s.h"

/*
** num_1.c, ...
*/

t_num		num_plus(t_num a, t_num b);
t_num		num_minus(t_num a, t_num b);
t_num		num_mult(t_num a, t_num b);
t_num		num_div(t_num a, t_num b);
t_num		num_sqr(t_num a);

t_num		num_min(t_num a, t_num b);
t_num		num_max(t_num a, t_num b);
t_num		num_clamp(t_num val, t_num min, t_num max);

#endif
