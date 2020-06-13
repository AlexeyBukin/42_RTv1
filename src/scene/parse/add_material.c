/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:19:57 by hush              #+#    #+#             */
/*   Updated: 2020/06/13 14:36:54 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	material_set_default(t_material *mat)
{
	if (mat == NULL)
		return ;
	mat->id = 0;
	mat->albedo = vec(0.6, 0.6, 0.6);
	mat->roughness = 0.5;
	mat->metalness = 0;
	mat->ior = 0.5;
	mat->f0 = vec(0, 0, 0);
}

int		mat_index(t_scene *scene, size_t id)
{
	size_t		i;

	if (scene == NULL)
		return (-1);
	if (scene->materials == NULL || scene->mat_num == 0)
		return (-1);
	i = 0;
	while (i < scene->mat_num)
	{
		if (scene->materials[i].id == id)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

/*
** F0 = ((1-ior)/(1+ior))²
*/

static
void	material_apply_parameters(t_material *mat)
{
	t_num		tmp_f0;

	if (mat == NULL)
		return ;
	tmp_f0 = num_sqr((1 - mat->ior) / (1 + mat->ior));
	if (mat->metalness == TRUE)
	{
		mat->f0 = mat->albedo;
		mat->albedo = vec_zero();
	}
	else
	{
		mat->f0 = vec(tmp_f0, tmp_f0, tmp_f0);
	}
}

int		scene_read_material(t_scene *scene, char **source, t_material *mat)
{
	if (source == NULL || mat == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if (*source == NULL)
		return (ft_puterror(2, "Dereference NULL pointer"));
	(*source) += ft_strlen(KEYWORD_MATERIAL);
	if(read_id((source), &(mat->id)) < 0 || mat_index(scene, mat->id) >= 0)
		return (ft_puterror(3, "Syntax error: expected correct id"));
	if (*((*source)++) != '(')
		return (ft_puterror(4, "Syntax error: expected \'(\' "));
	if (read_num_bound(source, &(mat->metalness), 0.0, 1.0) < 0)
		return (ft_puterror(5, "Syntax error: expected metalness number"));
	if (read_vec_after_comma(source, &(mat->albedo)) < 0)
		return (ft_puterror(6, "Syntax error: expected color vector"));
	if (read_num_bound_after_comma(source, &(mat->roughness), 0.0, 1.0) < 0)
		return (ft_puterror(7, "Syntax error: expected roughness number"));
	if (read_num_bound_after_comma(source, &(mat->ior), 1.0, 10.0) < 0)
		return (ft_puterror(8, "Syntax error: expected IOR number"));
	if (*((*source)++) != ')')
		return (ft_puterror(9, "Syntax error: expected \')\' "));
	material_apply_parameters(mat);
	return (0);
}

int			scene_add_material(t_scene *scene, char **source)
{
	if (scene == NULL)
		return (ft_puterror(1,"scene is NULL pointer"));
	scene->materials = (t_material*)ft_realloc_arr(scene->materials, scene->mat_num,
			scene->mat_num + 1, sizeof(t_material));
	if (scene->materials == NULL)
		return (ft_puterror(2,"Realloc material returned NULL"));
	if (scene_read_material(scene, source, &(scene->materials[scene->mat_num])) < 0)
		return (ft_puterror(3, "Cannot read material"));
	scene->mat_num++;
	return (0);
}
