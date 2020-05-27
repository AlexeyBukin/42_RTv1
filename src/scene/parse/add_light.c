/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 03:11:40 by hush              #+#    #+#             */
/*   Updated: 2020/05/24 03:26:46 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static
int		scene_read_light(char **source, t_light *light)
{
	t_vec			vec;
	char 			*text;

	if (source == NULL || light == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if ((text = *source) == NULL)
		return (ft_puterror(2, "Dereference to NULL pointer"));
	text += ft_strlen(KEYWORD_LIGHT);
	if (*(text++) != '(')
		return (ft_puterror(3, "Expected \'(\' "));
	read_vec(&text, &(light->pos));
	if (!read_comma(&text))
		return (ft_puterror(4, "Expected \',\' "));
	if (read_vec(&text, &(vec)) < 0)
		light->col = col(255, 255, 255);
	else
	{
		light->col = col_from_vec(vec);
		if (!read_comma(&text))
			return (ft_puterror(5, "Expected \',\' "));
	}
	light->power = read_num(&text);
	if (*(text++) != ')')
		return (ft_puterror(6, "Expected \')\' "));
	*source = text;
	return (0);
}

int			scene_add_light(t_scene *scene, char **source)
{
	scene->lights = ft_realloc_arr(scene->lights, scene->light_num,
			scene->light_num + 1, sizeof(t_figure));
	if (scene->figures == NULL)
		return (ft_puterror(1,"Realloc figure returned NULL"));
	if (scene_read_light(source, &(scene->lights[scene->light_num])) < 0)
		return (ft_puterror(2, "Cannot read light"));
	scene->light_num++;
	return (0);
}
