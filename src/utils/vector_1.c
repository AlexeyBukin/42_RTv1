/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:37:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/08 20:53:16 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	vec_plus(t_vec a, t_vec b)
{
	return (vec_do_vec(a, b, num_plus));
}

t_vec	vec_minus(t_vec a, t_vec b)
{
	return (vec_do_vec(a, b, num_minus));
}

t_vec		vec_mult(t_vec a, t_vec b)
{
	return (vec_do_vec(a, b, num_mult));
}

t_vec		vec_div(t_vec a, t_vec b)
{
	return (vec_do_vec(a, b, num_div));
}

t_vec		vec_sqr(t_vec a)
{
	return (vec_do_vec(a, a, num_mult));
}
