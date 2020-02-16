/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:14:06 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/16 18:14:06 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		color_alpha(t_byte red, t_byte green, t_byte blue, t_byte alpha)
{
	t_color		col;

	col.r = red;
	col.g = green;
	col.b = blue;
	col.a = alpha;
	return (col);
}

t_color		color(t_byte red, t_byte green, t_byte blue)
{
	t_color		col;

	col.r = red;
	col.g = green;
	col.b = blue;
	col.a = ALPHA_MAX;
	return (col);
}
