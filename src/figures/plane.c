/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:04:16 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/02 17:37:46 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_base_fig_plane		*fig_plane_create(void)
{
	t_base_fig_plane		*plane;

	if ((plane = (t_base_fig_plane*)malloc(sizeof(t_base_fig_plane))) == NULL)
		return (ft_puterr_null(1, "fig_plane_create(): cannot"
		" malloc scene struct"));
	plane->type = FIG_PLANE;
	plane->pos = (t_double3){4.0, 0.0, -1.0};
	plane->a = (t_double3){4.0, 0.0, -1.0};
	plane->b = (t_double3){4.0, 0.0, -1.0};
	plane->col = color(128, 128, 128);
	return (plane);
}
