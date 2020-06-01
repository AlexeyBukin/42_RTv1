/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 23:22:27 by hush              #+#    #+#             */
/*   Updated: 2020/06/01 14:57:20 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num		num_sqr(t_num a)
{
	return (a * a);
}

int			num_cmp(t_num a, t_num b)
{
	if (a == b)
		return (0);
	return (a > b ? 1 : -1);
}

/*
** from.x = from_min;
** from.y = from_max;
** to.x = to_min;
** to.y = to_max;
** return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
*/

t_num		num_map(t_num num, t_vec from, t_vec to)
{
	num -= from.x;
	num *= to.y - to.x;
	num /= from.y - from.x;
	num += to.x;
	return (num);
}

t_num		num_clamp(t_num val, t_num min, t_num max)
{
	if (val < min)
	{
		return (min);
	}
	if (val > max)
	{
		return (max);
	}
	return (val);
}
