/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 23:22:27 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 20:19:26 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num		num_plus(t_num a, t_num b)
{
	return (a + b);
}

t_num		num_minus(t_num a, t_num b)
{
	return (a - b);
}

t_num		num_mult(t_num a, t_num b)
{
	return (a * b);
}

t_num		num_div(t_num a, t_num b)
{
	return (a / b);
}

t_num		num_sqr(t_num a)
{
	return (a * a);
}
