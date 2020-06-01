/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:39:30 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/01 15:15:41 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_col		col_from_vec_norm(t_vec vector)
{
	t_col	res;

	res.r = num_clamp(vector.x, 0, 1) * COLOR_MAX;
	res.g = num_clamp(vector.y, 0, 1) * COLOR_MAX;
	res.b = num_clamp(vector.z, 0, 1) * COLOR_MAX;
	res.a = ALPHA_MAX;
	return (res);
}

t_col		col_from_vec(t_vec vector)
{
	t_col	res;

	res.r = vector.x;
	res.g = vector.y;
	res.b = vector.z;

//	res.r = (t_byte)num_clamp(vector.x, 0.0, 255.0);
//	res.g = (t_byte)num_clamp(vector.y, 0.0, 255.0);
//	res.b = (t_byte)num_clamp(vector.z, 0.0, 255.0);
	res.a = ALPHA_MAX;
	return (res);
}

t_col		col_alpha(t_byte red, t_byte green, t_byte blue, t_byte alpha)
{
	t_col		col;

	col.r = red;
	col.g = green;
	col.b = blue;
	col.a = alpha;
	return (col);
}

t_col		col(t_byte red, t_byte green, t_byte blue)
{
	t_col		col;

	col.r = red;
	col.g = green;
	col.b = blue;
	col.a = ALPHA_MAX;
	return (col);
}

char		*col_to_str(t_col color)
{
	char	*res;

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

char		*col_to_str_color(t_col color)
{
	char	*res;

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
