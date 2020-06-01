/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:09:01 by hush              #+#    #+#             */
/*   Updated: 2020/06/01 04:38:57 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec		vec_from_color(t_col c)
{
	t_vec		res;

	res.x = (t_num) c.r / 255.0;
	res.y = (t_num) c.g / 255.0;
	res.z = (t_num) c.b / 255.0;
	return (res);
}

t_vec		vec_mult(t_vec a, t_vec b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_vec		vec2d(t_num newx, t_num newy)
{
	return (vec(newx, newy, 0));
}