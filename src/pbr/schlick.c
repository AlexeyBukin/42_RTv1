/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schlick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:41:17 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 18:47:57 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** return F0 + (1.0 - F0) * pow(1.0 - saturate(cosTheta), 5.0);
*/

t_vec	fresnel_schlick(t_vec f0, t_num cos_theta)
{
	t_vec	res;

	cos_theta = 1.0 - num_clamp(cos_theta, 0.0, 1.0);
	cos_theta = cos_theta * cos_theta * cos_theta * cos_theta * cos_theta;
	res = vec_mult_num(vec_minus(vec(1.0, 1.0, 1.0), f0), cos_theta);
	res = vec_plus(f0, res);
	//res = vec_plus(f0, vec_minus(vec(1.0, 1.0, 1.0), f0));
	//res = vec_mult_num(res, cos_theta);
	return (res);
}