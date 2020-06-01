/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 23:22:27 by hush              #+#    #+#             */
/*   Updated: 2020/06/01 04:49:39 by hush             ###   ########.fr       */
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
** to.y = to_max;
** toy = to_max;
** TODO map() implementation
*/

t_num		num_map(t_num num, t_vec from, t_vec to)
{
	(void)num;
	(void)from;
	(void)to;
	return (1);
}