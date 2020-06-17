/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:53 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/08 20:55:08 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec		vec_plus_num(t_vec v, t_num n)
{
	return (vec_do_num(v, n, num_plus));
}

t_vec		vec_minus_num(t_vec v, t_num n)
{
	return (vec_do_num(v, n, num_minus));
}

t_vec		vec_mult_num(t_vec v, t_num n)
{
	return (vec_do_num(v, n, num_mult));
}

t_vec		vec_div_num(t_vec v, t_num n)
{
	return (vec_do_num(v, n, num_div));
}

t_num		vec_sum(t_vec v)
{
	return (v.x + v.y + v.z);
}
