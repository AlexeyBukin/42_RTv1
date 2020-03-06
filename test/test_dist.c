/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:07:25 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/06 03:10:00 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main()
{
	t_double3	a = {10, 11, 12};
	t_double3	b = {1, 2, 3};

	double dist_sqr = d3_dist_sqr(a, b);
	double dist = d3_dist(a, b);
	char * str = d3_to_str(b);

	t_double3 plus = d3_plus(a, b);
	t_double3 mult = d3_mult(a, 3.0);
	t_double3 minus = d3_minus(a, b);

	printf("dist_sqr = %f\ndist = %f\n", dist_sqr, dist);
	printf("a = %s\n", d3_to_str(a));
	printf("b = %s\n", d3_to_str(b));
	printf("plus = %s\n", d3_to_str(plus));
	printf("minus = %s\n", d3_to_str(minus));
	printf("mult = %s\n", d3_to_str(mult));
	free(str);
}

//gcc -g build/double3.o src/test/test_dist.c -I include -I libft/include libft/libft.a -I libsdl/include/SDL2 -Wall -Wextra -Werror
