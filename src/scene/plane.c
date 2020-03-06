/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:04:16 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 04:56:01 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray 				trace_plane_bounce(t_ray ray, t_base_fig *fig)
{
	//TODO redo normally
	(void)fig;
	return (ray);
}

t_dot				trace_plane(t_dot orig, t_vec dir, t_base_fig *fig)
{
    t_base_fig_plane	*pl;
    double              denom;
	double				t;

    if (fig == NULL)
        return (d3_get_inf());
    pl = (t_base_fig_plane*)fig;
    if (pl->type != FIG_PLANE)
        return (d3_get_inf());
    denom = vec_dot_product(pl->n, dir);
    if (ft_absd(denom) < EPSILON)
        return (d3_get_inf());
    t = -1 * (vec_dot_product(pl->n, orig) + pl->d) / denom;
    if (t < EPSILON)
        return (d3_get_inf());
    return (d3_plus(orig, d3_mult(dir, t)));
}

t_base_fig      	*fig_plane_create(t_vec normal, double arg_d, t_color col)
{
	t_base_fig_plane		*plane;

	if ((plane = (t_base_fig_plane*)fig_create()) == NULL)
		return (ft_puterr_null(1, "fig_plane_create(): cannot"
		" malloc scene struct"));
	plane->type = FIG_PLANE;
	plane->d = arg_d;
	plane->n = normal;
	plane->col = col;
	return ((t_base_fig*)plane);
}
