/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:14:06 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/17 21:40:02 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_col		col_add(t_col a, t_col b)
{
	a.r = ((int)(a.r + b.r)) > 255 ? 255 : (a.r + b.r);
	a.g = ((int)(a.g + b.g)) > 255 ? 255 : (a.g + b.g);
	a.b = ((int)(a.b + b.b)) > 255 ? 255 : (a.b + b.b);
	a.a = ((int)(a.a + b.a)) > 255 ? 255 : (a.a + b.a);
	return (a);
}

/*
** Inside integer colors scheme are ARGB
*/

int			col_to_int(t_col col)
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

t_col		col_from_int(int src)
{
	t_col		col;

	col.b = src & 255;
	col.g = (src >> 8) & 255;
	col.g = (src >> 16) & 255;
	col.g = (src >> 24) & 255;
	return (col);
}

t_col		col_from_normal(t_vec vector)
{
	t_col	res;

	vector = vec_normalize(vector);
	res.r = (vector.x + 1) * COLOR_MAX / 2;
	res.g = (vector.y + 1) * COLOR_MAX / 2;
	res.b = (vector.z + 1) * COLOR_MAX / 2;
	res.a = ALPHA_MAX;
	return (res);
}

t_col		col_from_vec_norm(t_vec vector)
{
	t_col	res;

	res.r = num_clamp(vector.x, 0, 1) * COLOR_MAX;
	res.g = num_clamp(vector.y, 0, 1) * COLOR_MAX;
	res.b = num_clamp(vector.z, 0, 1) * COLOR_MAX;
	res.a = ALPHA_MAX;
	return (res);
}
