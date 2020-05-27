/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 11:48:52 by hush              #+#    #+#             */
/*   Updated: 2020/05/24 23:23:32 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray		ray_inf()
{
	return ((t_ray){vec_inf(), vec_inf()});
}

int			vec_cmp_len(t_vec a, t_vec b)
{
	return (num_cmp(vec_dist_sqr(vec_zero(), a), vec_dist_sqr(vec_zero(), b)));
}

t_vec		vec_zero()
{
	return ((t_vec){0, 0, 0});
}

t_bool		vec_is_zero(t_vec a)
{
	return (a.x == 0 && a.y == 0 && a.z == 0);
}
