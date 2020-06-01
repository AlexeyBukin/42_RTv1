/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:19:57 by hush              #+#    #+#             */
/*   Updated: 2020/06/02 02:22:12 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	material_set_default(t_material *mat)
{
	if (mat == NULL)
		return ;
	mat->id = 0;
	mat->col = vec(0.6, 0.6, 0.6);
	mat->roughness = 0.5;
	mat->metallic = 0;
	mat->specular = 0.5;
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

int		scene_read_material(t_scene *scene, char **source, t_material *mat)
{
	char 			*text;

	if (source == NULL || mat == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if ((text = *source) == NULL)
		return (ft_puterror(2, "Dereference NULL pointer"));
	text += ft_strlen(KEYWORD_MATERIAL);
	if(read_id((&text), &(mat->id)) < 0 || mat_index(scene, mat->id) >= 0)
		return (ft_puterror(3, "Syntax error: expected correct id"));
	if (*(text++) != '(')
		return (ft_puterror(5, "Syntax error: expected \'(\' "));
	if (read_vec(&text, &(mat->col)) < 0)
		return (ft_puterror(6, "Syntax error: expected color vector"));
	if (!read_comma(&text))
		return (ft_puterror(7, "Syntax error: expected \',\' "));
	if (read_vec(&text, (t_vec*)&(mat->roughness)) < 0)
		return (ft_puterror(6, "Syntax error: expected pbr vector"));
	if (!read_comma(&text))
		return (ft_puterror(7, "Syntax error: expected \',\' "));
	if (read_vec(&text, &(mat->f0)) < 0)
		return (ft_puterror(6, "Syntax error: expected f0 vector"));
	if (*(text++) != ')')
		return (ft_puterror(10, "Syntax error: expected \')\' "));
	*source = text;
	return (0);
}

int			scene_add_material(t_scene *scene, char **source)
{
	scene->materials = (t_material*)ft_realloc_arr(scene->materials, scene->mat_num,
			scene->mat_num + 1, sizeof(t_material));
	if (scene->materials == NULL)
		return (ft_puterror(1,"Realloc material returned NULL"));
	if (scene_read_material(scene, source, &(scene->materials[scene->mat_num])) < 0)
		return (ft_puterror(2, "Cannot read material"));
	scene->mat_num++;
	return (0);
}
