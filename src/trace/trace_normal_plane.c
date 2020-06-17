/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_bounce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:00:39 by hush              #+#    #+#             */
/*   Updated: 2020/05/25 03:39:17 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec				trace_normal_plane(t_ray ray, t_figure *fig)
{
	if (fig == NULL)
		return (vec_inf());
	if (fig->figs.plane.n.x * ray.pos.x + fig->figs.plane.n.y * ray.pos.y
		+ fig->figs.plane.n.z * ray.pos.z + fig->figs.plane.d < 0)
		return (vec_invert(fig->figs.plane.n));
	return (fig->figs.plane.n);
}
