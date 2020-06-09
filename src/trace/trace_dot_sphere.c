/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_dot_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:10:07 by hush              #+#    #+#             */
/*   Updated: 2020/06/09 11:22:43 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static
t_vec 				sphere_intersect_points(t_ray ray, t_sphere sphere)
{
	t_vec		t;
	t_num		a;
	t_num		b;
	t_num		c;
	t_num 		d;

	t_vec		a_min_c;
	a_min_c = vec_minus(ray.pos, sphere.pos);

	a = vec_dot(ray.dir, ray.dir);
	b = 2 * vec_dot(ray.dir, a_min_c);
	c = vec_dot(a_min_c, a_min_c) - (sphere.r * sphere.r);

	d = (b * b) - 4 * a * c;

	//ft_printf("d is %f\n", d);
	if (d < 0)
		return (vec_inf());

	//points.dir = (-b - sqrt(d)) / (2 * a);
	//points.pos = (-b + sqrt(d)) / (2 * a);
	t.x = (-b - sqrt(d)) / (2 * a);
	t.y = (-b + sqrt(d)) / (2 * a);
	return (t);
}

t_num				trace_dot_sphere(t_ray ray, t_figure *fig)
{
	t_num			minimal;
	t_vec			points;

	if (fig == NULL)
		return (INFINITY);
	points = sphere_intersect_points(ray, fig->sphere);
	minimal = INFINITY;
	if (points.x > 0 && points.x < minimal)
		minimal = points.x;
	if (points.y > 0 && points.y < minimal)
		minimal = points.y;
	return (minimal);
}

