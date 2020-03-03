/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:39:30 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/02 17:39:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char		*color_to_str(t_color color)
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

char		*color_to_str_color(t_color color)
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
