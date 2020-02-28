/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:33:56 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/28 23:36:41 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		get_inf()
{
	double				d;
	unsigned long long	ull;

	ull = INFINITY_POSITIVE_RAW;
	ft_memcpy(&d, &ull, sizeof(double));
	return (d);
}

t_bool		is_inf(double d)
{
	unsigned long long ull;

	ull = INFINITY_POSITIVE_RAW;
	if (ft_memcmp(&d, &ull, sizeof(double)) == 0)
		return (TRUE);
	return (FALSE);
}

t_double3	d3_get_inf()
{
	t_double3	a;

	a.x = get_inf();
	a.y = get_inf();
	a.z = get_inf();
	return (a);
}

t_bool		d3_is_inf(t_double3 a)
{
	return (is_inf(a.x) || is_inf(a.y) || is_inf(a.z));
}
