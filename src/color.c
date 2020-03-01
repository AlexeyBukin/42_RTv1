/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:14:06 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/01 18:40:48 by kcharla          ###   ########.fr       */
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

//todo 	if slow col = mask.r * (col.r > mask.r) + col * !(col.r > mask.r);
t_color		col_mask(t_color col, t_color mask)
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

char * color_to_str(t_color color)
{
	char * res;

	res = ft_strjoin_free(ft_strdup("(r: "), ft_itoa(color.r));
	res = ft_strjoin_free(res, ft_strdup("; g: "));
	res = ft_strjoin_free(res, ft_itoa(color.g));
	res = ft_strjoin_free(res, ft_strdup("; b: "));
	res = ft_strjoin_free(res, ft_itoa(color.b));
	res = ft_strjoin_free(res, ft_strdup("; a: "));
	res = ft_strjoin_free(res, ft_itoa(color.a));
	res = ft_strjoin_free(res, ft_strdup(")"));
	return (res);
}

char * color_to_str_color(t_color color)
{
	char * res;

	res = ft_strjoin_free(ft_strdup("(\033[0;31mr: "), ft_itoa(color.r));
	res = ft_strjoin_free(res, ft_strdup("\033[0m; \033[0;32mg: "));
	res = ft_strjoin_free(res, ft_itoa(color.g));
	res = ft_strjoin_free(res, ft_strdup("\033[0m; \033[0;34mb: "));
	res = ft_strjoin_free(res, ft_itoa(color.b));
	res = ft_strjoin_free(res, ft_strdup("\033[0m; a: "));
	res = ft_strjoin_free(res, ft_itoa(color.a));
	res = ft_strjoin_free(res, ft_strdup(")"));
	return (res);
}
