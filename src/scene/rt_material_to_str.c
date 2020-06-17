/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_material.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:58:34 by hush              #+#    #+#             */
/*   Updated: 2020/06/13 13:52:23 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char				*material_to_str(t_material *mat)
{
	char			*res;

	if (mat == NULL)
		return (ft_puterr_null(1, "plain_to_str(): NULL pointer"));
	res = ft_strdup("material[");
	res = ft_strjoin_free(res, ft_lltoa(mat->id));
	res = ft_str_add(res, "]( metalness:");
	res = ft_strjoin_free(res, ft_ldtoa(mat->metalness));
	res = ft_str_add(res, ", albedo:");
	res = ft_strjoin_free(res, vec_to_str_color(mat->albedo));
	res = ft_str_add(res, ", roughness:");
	res = ft_strjoin_free(res, ft_ldtoa(mat->roughness));
	res = ft_str_add(res, ", ior:");
	res = ft_strjoin_free(res, ft_ldtoa(mat->ior));
	res = ft_str_add(res, ", f0:");
	res = ft_strjoin_free(res, vec_to_str_color(mat->f0));
	res = ft_str_add(res, ")");
	return (res);
}
