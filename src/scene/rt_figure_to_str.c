/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:58:38 by hush              #+#    #+#             */
/*   Updated: 2020/06/17 23:21:19 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char				*plain_to_str(t_plane *plane, t_material *material)
{
	char			*res;

	if (plane == NULL || material == NULL)
		return (ft_puterr_null(1, "plain_to_str(): NULL pointer"));
	res = ft_strdup("plane[");
	res = ft_strjoin_free(res, ft_lltoa(material->id));
	res = ft_str_add(res, "]( A:");
	res = ft_strjoin_free(res, ft_ldtoa(plane->n.x));
	res = ft_str_add(res, ", B:");
	res = ft_strjoin_free(res, ft_ldtoa(plane->n.y));
	res = ft_str_add(res, ", C:");
	res = ft_strjoin_free(res, ft_ldtoa(plane->n.z));
	res = ft_str_add(res, ", D:");
	res = ft_strjoin_free(res, ft_ldtoa(plane->d));
	res = ft_str_add(res, ")");
	return (res);
}

char				*sphere_to_str(t_sphere *sphere, t_material *material)
{
	char			*res;

	if (sphere == NULL || material == NULL)
		return (ft_puterr_null(1, "sphere_to_str(): NULL pointer"));
	res = ft_strdup("sphere[");
	res = ft_strjoin_free(res, ft_lltoa(material->id));
	res = ft_str_add(res, "]( position:");
	res = ft_strjoin_free(res, vec_to_str_color(sphere->pos));
	res = ft_str_add(res, ", radius:");
	res = ft_strjoin_free(res, ft_ldtoa(sphere->r));
	res = ft_str_add(res, ")");
	return (res);
}

char				*cone_to_str(t_cone *cone, t_material *material)
{
	char			*res;

	if (cone == NULL || material == NULL)
		return (ft_puterr_null(1, "cone_to_str(): NULL pointer"));
	res = ft_strdup("cone[");
	res = ft_strjoin_free(res, ft_lltoa(material->id));
	res = ft_str_add(res, "]( position:");
	res = ft_strjoin_free(res, vec_to_str_color(cone->pos));
	res = ft_str_add(res, ", top:");
	res = ft_strjoin_free(res, vec_to_str_color(cone->cap));
	res = ft_str_add(res, ", radius:");
	res = ft_strjoin_free(res, ft_ldtoa(cone->r));
	res = ft_str_add(res, ")");
	return (res);
}

char				*cyl_to_str(t_cylinder *cyl, t_material *material)
{
	char			*res;

	if (cyl == NULL || material == NULL)
		return (ft_puterr_null(1, "cyl_to_str(): NULL pointer"));
	res = ft_strdup("cylinder[");
	res = ft_strjoin_free(res, ft_lltoa(material->id));
	res = ft_str_add(res, "]( position:");
	res = ft_strjoin_free(res, vec_to_str_color(cyl->pos));
	res = ft_str_add(res, ", top:");
	res = ft_strjoin_free(res, vec_to_str_color(cyl->cap));
	res = ft_str_add(res, ", radius:");
	res = ft_strjoin_free(res, ft_ldtoa(cyl->r));
	res = ft_str_add(res, ")");
	return (res);
}

char				*figure_to_str(t_figure *fig)
{
	if (fig == NULL)
		return (ft_puterr_null(1, "figure_to_str(): NULL pointer"));
	if (fig->type == FIG_PLANE)
		return (plain_to_str(&(fig->plane), fig->mat));
	else if (fig->type == FIG_SPHERE)
		return (sphere_to_str(&(fig->sphere), fig->mat));
	else if (fig->type == FIG_CONE)
		return (cone_to_str(&(fig->cone), fig->mat));
	else if (fig->type == FIG_CYL)
		return (cyl_to_str(&(fig->cyl), fig->mat));
	else
		return (ft_puterr_null(2, "figure_to_str(): unknown FIGURE"));
}
