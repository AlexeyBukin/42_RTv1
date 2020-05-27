/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:19:57 by hush              #+#    #+#             */
/*   Updated: 2020/05/24 02:23:33 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** create and fill scene
** TODO add puterror()
** TODO delete skip_comments
*/

int		mat_index(t_scene *scene, long id)
{
	size_t		i;

	if (scene == NULL || id < 0)
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
	t_vec			vcol;
	char 			*text;

	if (source == NULL || mat == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if ((text = *source) == NULL)
		return (ft_puterror(2, "Entered NULL pointer"));
	text += ft_strlen(KEYWORD_MATERIAL);
	if((mat->id = read_id(&text)) == 0 || mat_index(scene, mat->id) >= 0)
		return (ft_puterror(3, "Parse error: expected correct id"));
	if (*(text++) != '(')
		return (ft_puterror(5, "Syntax error: expected \'(\' "));
	if (read_vec(&text, &vcol) < 0)
		return (ft_puterror(6, "Parse error: expected color"));
	mat->col = col_from_vec(vcol);
	if (!read_comma(&text))
		return (ft_puterror(7, "Syntax error: expected \',\' "));
	mat->col.a = read_num(&text);
	if (!read_comma(&text))
		return (ft_puterror(8, "Syntax error: expected \',\' "));
	if (read_vec(&text, &vcol) < 0)
		return (ft_puterror(9, "Parse error: expected pbr parameters"));
	*((t_vec*)&(mat->roughness)) = vcol;
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
