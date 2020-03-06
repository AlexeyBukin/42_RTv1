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

//--------------------------------------------------------------------------//
//Ray : P(t) = O + V * t// Cylinder [O, D, r].// point Q on cylinder
if ((Q - O) x D)^2 = r^2//// Cylinder [A, B, r].// Point P on infinite cylinder if ((P - A) x (B - A))^2 = r^2 * (B - A)^2// expand : ((O - A) x (B - A) + t * (V x (B - A)))^2 = r^2 * (B - A)^2// equation in the form (X + t * Y)^2 = d// where : //  X = (O - A) x (B - A)//  Y = V x (B - A)//  d = r^2 * (B - A)^2// expand the equation :// t^2 * (Y . Y) + t * (2 * (X . Y)) + (X . X) - d = 0// => second order equation in the form : a*t^2 + b*t + c = 0 where// a = (Y . Y)// b = 2 * (X . Y)// c = (X . X) - d//--------------------------------------------------------------------------Vector AB = (B - A);Vector AO = (O - A);Vector AOxAB = (AO ^ AB); // cross productVector
/// VxAB  = (V ^ AB); // cross productfloat  ab2   = (AB * AB); // dot productfloat a      = (VxAB * VxAB); // dot productfloat b      = 2 * (VxAB * AOxAB); // dot productfloat c      = (AOxAB * AOxAB) - (r*r * ab2);// solve second order equation : a*t^2 + b*t + c = 0


#include "rtv1.h"

int		main()
{
//	t_double3	a = {10, 11, 12};
//	t_double3	b = {1, 2, 3};
//
//	double dist_sqr = d3_dist_sqr(a, b);
//	double dist = d3_dist(a, b);
//	char * str = d3_to_str(b);
//
//	t_double3 plus = d3_plus(a, b);
//	t_double3 mult = d3_mult(a, 3.0);
//	t_double3 minus = d3_minus(a, b);
//
//	printf("dist_sqr = %f\ndist = %f\n", dist_sqr, dist);
//	printf("a = %s\n", d3_to_str(a));
//	printf("b = %s\n", d3_to_str(b));
//	printf("plus = %s\n", d3_to_str(plus));
//	printf("minus = %s\n", d3_to_str(minus));
//	printf("mult = %s\n", d3_to_str(mult));
//	free(str);
	t_rtv1	*rtv1;

	rtv1 = NULL;
	if (rtv1_init(&rtv1) < 0)
	{
		//rtv1_quit(rtv1);
		return (ft_puterror(1, "main(): problems running rtv1_init()"));
	}
	t_color traced = trace(rtv1, (t_double3){0.0, 0.0, 0.0}, (t_double3){1.0, 0.0, 0.0});
	ft_printf("%-30s - %-30s", "traced: ", color_to_str_color(traced));
}

//gcc -g  src/*.c src/test/test_trace.c -I include -I libft/include libft/libft.a libsdl/lib/libSDL2.dylib -I libsdl/include/SDL2 -Wall -Wextra -Werror


//old//gcc -g build/double3.o src/test/test_trace.c src/init.c -I include -I libft/include libft/libft.a -I libsdl/include/SDL2 -Wall -Wextra -Werror
