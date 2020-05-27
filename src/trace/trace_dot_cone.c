/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_dot_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:09:43 by hush              #+#    #+#             */
/*   Updated: 2020/05/24 14:09:43 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num					trace_dot_cone(t_ray ray, t_figure *fig)
{
	t_plane				*pl;
	t_num				denom;
	t_num				t;

	if (fig == NULL)
		return (INFINITY);
	pl = &(fig->plane);
	if (fig->type != FIG_PLANE)
		return (INFINITY);
	denom = vec_dot_product(pl->n, ray.dir);
	if (ft_absd(denom) < EPSILON)
		return (INFINITY);
	t = -1 * (vec_dot_product(pl->n, ray.pos) + pl->d) / denom;
	if (t < EPSILON)
		return (INFINITY);
	return (t);
}
