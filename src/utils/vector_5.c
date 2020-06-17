/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:09:01 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 21:11:25 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num		vec_dist_sqr(t_vec a, t_vec b)
{
	return (vec_sum(vec_sqr(vec_minus(a, b))));
}

t_num		vec_dist(t_vec a, t_vec b)
{
	return (sqrt(vec_dist_sqr(a, b)));
}

t_num		vec_len(t_vec a)
{
	return (vec_dist(vec_zero(), a));
}

t_vec		vec_max(t_vec a, t_vec b)
{
	return (vec_do_vec(a, b, num_max));
}

t_vec		vec_min(t_vec a, t_vec b)
{
	return (vec_do_vec(a, b, num_min));
}
