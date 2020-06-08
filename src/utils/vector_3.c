/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:35 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/08 20:34:48 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec			vec(t_num x, t_num y, t_num z)
{
	return ((t_vec){x, y, z});
}

t_vec			vec_zero()
{
	return ((t_vec){0, 0, 0});
}

t_bool			vec_is_zero(t_vec a)
{
	return (a.x == 0 && a.y == 0 && a.z == 0);
}

t_bool
vec_is_inf(t_vec a)
{
	return (isinf(a.x) || isinf(a.y) || isinf(a.z));
}

t_vec			vec_inf()
{
	return ((t_vec){INFINITY, INFINITY, INFINITY});
}