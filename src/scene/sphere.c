/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:04:16 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/28 01:03:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray				trace_sphere_bounce(t_ray ray, t_base_fig *fig)
{
	t_base_fig			plane;
	t_ray				bounce;

	if (fig == NULL)
		return (ray_get_inf());
	bounce.pos = trace_sphere(ray, fig);
	plane.plane.n = d3_minus(fig->sphere.pos, bounce.pos);
	bounce.dir = trace_plane_bounce(ray, &plane).dir;
	return (bounce);
}

//TODO redo, render bug when sphere behind camera
t_double3		trace_sphere(t_ray ray, t_base_fig *fig)
{
	t_base_fig_sphere	*s;
	t_double3	ao;
	double		cos_a;
	double		sin_a;
	double		dist;
	double		perp;
	double		square;
	double		root;
	double		ac_len;
	t_double3	c;
	t_double3	result;

	if (fig == NULL)
		return(d3_get_inf());
	s = (t_base_fig_sphere *)fig;
	if (s->type != FIG_SPHERE)
		return(d3_get_inf());
	ao = d3_minus(s->pos, ray.pos);
	ray.dir = vec_normalize(ray.dir);
	dist = vec_len(ao);
	if (dist < 0)
		ft_printf("ENORMOUS!!\n");
	square = vec_dot_product(ao, ray.dir);
	cos_a = square / (dist);
	sin_a = sqrt(1.0 - cos_a * cos_a);
	perp = dist * sin_a;
	if (perp > s->r)
		return(d3_get_inf());
//debug
	//return(s->pos);

	ac_len = dist * cos_a;
	c = d3_plus(ray.pos, d3_mult(ray.dir, ac_len));
	root = sqrt(s->r * s->r - perp * perp);
	result = d3_minus(c, d3_mult(ray.dir, root));
	return (result);
}

t_base_fig_sphere	fig_sphere_get(void)
{
	t_base_fig_sphere		sphere;

	sphere.type = FIG_SPHERE;
	sphere.pos = (t_double3){5.0, 2.0, 2.0};
	sphere.r = 1;
	sphere.col = color(255, 128, 128);
	return (sphere);
}

t_base_fig_sphere	*fig_sphere_create_default(void)
{
	t_base_fig_sphere		*sphere;

	if ((sphere = (t_base_fig_sphere*)fig_create()) == NULL)
		return (ft_puterr_null(1, "fig_sphere_create():"
							" cannot malloc scene struct"));
	*sphere = fig_sphere_get();
	return (sphere);
}

t_base_fig_sphere	*fig_sphere_create(t_dot pos, double radius, t_color col)
{
	t_base_fig_sphere		*sphere;

	if ((sphere = (t_base_fig_sphere*)fig_create()) == NULL)
		return (ft_puterr_null(1, "fig_sphere_create():"
								  " cannot malloc scene struct"));
	sphere->pos = pos;
	sphere->col = col;
	sphere->r = radius;
	sphere->type = FIG_SPHERE;
	return (sphere);
}