/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 21:24:30 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 21:24:30 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			vec_point_is_behind(t_vec vec_from_zero, t_vec point)
{
	if (vec_sum(vec_mult(vec_from_zero, point)) < 0)
		return (TRUE);
	return (FALSE);
}

t_vec			vec_clamp(t_vec source, t_num min, t_num max)
{
	source.x = num_clamp(source.x, min, max);
	source.y = num_clamp(source.y, min, max);
	source.z = num_clamp(source.z, min, max);
	return (source);
}

t_vec			vec_max_num(t_vec v, t_num n)
{
	return (vec_max(v, vec(n, n, n)));
}

t_vec			vec_max_min(t_vec v, t_num n)
{
	return (vec_min(v, vec(n, n, n)));
}
