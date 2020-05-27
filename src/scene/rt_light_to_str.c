/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:59:25 by hush              #+#    #+#             */
/*   Updated: 2020/05/27 17:03:10 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char				*light_to_str(t_light *light)
{
	char 	*res;

	if (light == NULL)
		return (ft_puterr_null(1, "plain_to_str(): NULL pointer"));
	res = ft_strdup("light( position");
	res = ft_strjoin_free(res, vec_to_str_color(light->pos));
	res = ft_str_add(res, ", color:");
	res = ft_strjoin_free(res, col_to_str_color(light->col));
	res = ft_str_add(res, ", power:");
	res = ft_strjoin_free(res, ft_ldtoa(light->power));
	res = ft_str_add(res, ")");
	return (res);
}
