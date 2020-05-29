/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:14:06 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/27 16:16:07 by hush             ###   ########.fr       */
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
** col_mask() constraints input values by mask
**
** if slow col = mask.r * (col.r > mask.r) + col * !(col.r > mask.r);
*/

t_col		col_mask(t_col col, t_col mask)
{
	if (col.r > mask.r)
		col.r = mask.r;
	if (col.g > mask.g)
		col.g = mask.g;
	if (col.b > mask.b)
		col.b = mask.b;
	if (col.a > mask.a)
		col.a = mask.a;
	return (col);
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
