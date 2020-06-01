/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_bounce_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:09:37 by hush              #+#    #+#             */
/*   Updated: 2020/05/25 03:43:02 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec				trace_normal_sphere(t_ray ray, t_figure *fig)
{
	t_vec				bounce_pos;

	if (fig == NULL)
		return (vec_inf());
	bounce_pos = vec_plus(ray.pos,
		vec_mult_num(ray.dir, trace_dot_sphere(ray, fig)));
	return (vec_normalize(vec_minus(bounce_pos, fig->sphere.pos)));
}
