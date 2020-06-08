/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:39:10 by hush              #+#    #+#             */
/*   Updated: 2020/06/08 17:39:34 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num		ggx_distribution(t_num cosThetaNH, t_num alpha)
{
	t_num alpha2 = alpha * alpha;
	t_num NH_sqr = num_clamp(num_sqr(cosThetaNH * cosThetaNH), 0, 1);
	t_num den = NH_sqr * alpha2 + (1.0 - NH_sqr);
	return (alpha2 / ( M_PI * den * den ));
}

t_num		ggx_partial_geometry(t_num cos_theta_n, t_num alpha)
{
	cos_theta_n = num_clamp(num_sqr(cos_theta_n), 0, 1);
	cos_theta_n = ( 1 - cos_theta_n ) / cos_theta_n;
	return (2.0 / ( 1.0 + sqrt( 1.0 + alpha * alpha * cos_theta_n)));
}
