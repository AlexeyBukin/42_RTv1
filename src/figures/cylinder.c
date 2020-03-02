/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:49:44 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/02 17:35:32 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** cyl->top = (t_double3){0.0, 0.0, 1.0};
** cyl->pos = (t_double3){0.0, 0.0, -1.0};
*/

t_base_fig_cyl		*fig_cyl_create(void)
{
	t_base_fig_cyl		*cyl;

	if ((cyl = (t_base_fig_cyl*)malloc(sizeof(t_base_fig_cyl)))
																	== NULL)
		return (ft_puterr_null(1, "fig_cyl_create(): cannot "
		"malloc scene struct"));
	cyl->type = FIG_CYLINDER;
	cyl->top = (t_double3){4.0, 0.0, 1.0};
	cyl->pos = (t_double3){3.0, 0.0, -1.0};
	cyl->r = 1;
	cyl->col = color(128, 128, 128);
	return (cyl);
}
