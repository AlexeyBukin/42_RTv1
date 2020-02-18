/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:14:06 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/18 19:01:27 by kcharla          ###   ########.fr       */
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

/*
** Inside integer colors scheme are ARGB
*/

int			color_to_int(t_color col)
{
	int		res;

	res = 0;
	res += col.a;
	res = res << 8;
	res += col.r;
	res = res << 8;
	res += col.g;
	res = res << 8;
	res += col.b;
	return (res);
}

t_color		color_from_int(int src)
{
	t_color		col;

	col.b = src & 255;
	col.g = (src >> 8) & 255;
	col.g = (src >> 16) & 255;
	col.g = (src >> 24) & 255;
	return (col);
}