/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:27:17 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 20:18:54 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num		num_min(t_num a, t_num b)
{
	return (a < b ? a : b);
}

t_num		num_max(t_num a, t_num b)
{
	return (a > b ? a : b);
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
