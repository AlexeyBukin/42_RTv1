/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:26:48 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/17 04:02:17 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		trace(t_rtv1 *rtv1, t_double3 direction)
{
	if (rtv1 == NULL)
		return (ft_puterror(1, "redraw(): pointer rtv1 is NULL"));
	(void)direction;
	return (color(255, 255, 255));
}
