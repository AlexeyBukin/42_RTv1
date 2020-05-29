/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:47:36 by hush              #+#    #+#             */
/*   Updated: 2020/03/26 14:47:36 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool		ray_point_is_behind(t_ray ray, t_vec point)
{
	return (vec_point_is_behind(ray.dir, vec_minus(point, ray.pos)));
}

t_ray		ray_inf()
{
	return ((t_ray){vec_inf(), vec_inf()});
}
