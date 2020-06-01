/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 12:07:43 by hush              #+#    #+#             */
/*   Updated: 2020/06/01 02:50:50 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int
scene_add_component(char **text, t_scene *scene)
{
	if (text == NULL || scene == NULL)
		return (ft_puterror(1, "Null pointers entered"));
	if (*text == NULL)
		return (ft_puterror(2, "Null pointer entered for *text"));
	if (ft_str_next_is(*text, KEYWORD_PLANE))
		return (scene_add_figure(scene, text, FIG_PLANE));
	if (ft_str_next_is(*text, KEYWORD_SPHERE))
		return (scene_add_figure(scene, text, FIG_SPHERE));
	if (ft_str_next_is(*text, KEYWORD_CONE))
		return (scene_add_figure(scene, text, FIG_CONE));
	if (ft_str_next_is(*text, KEYWORD_CYLINDER))
		return (scene_add_figure(scene, text, FIG_CYL));
	else if (ft_str_next_is(*text, KEYWORD_MATERIAL))
		return (scene_add_material(scene, text));
	else if (ft_str_next_is(*text, KEYWORD_LIGHT))
		return (scene_add_light(scene, text));
	return (ft_puterror(3, "Expected known keywords"));
}

static int
scene_parse(char *text, t_scene *scene)
{
	t_bool		expect_next;

	if (text == NULL || scene == NULL)
		return (ft_puterror(1, "Null pointers entered"));
	if (*text != '(')
		return (ft_puterror(2, "Expected \'(\'"));
	text++;
	expect_next = TRUE;
	while (expect_next)
	{
		if (scene_add_component(&text, scene) < 0)
			return (ft_puterror(3, "Cannot add component to scene"));
		expect_next = read_comma(&text);
	}
	if (ft_strcmp(text, ")") != 0)
		return (ft_puterror(4, "Expected \')\' and EOF"));
	return (0);
}

static int
scene_link_ids(t_scene *scene)
{
	long		index;
	size_t		i;

	if (scene == NULL)
		return (-1);
	i = 0;
	while (i < scene->fig_num)
	{
		if ((index = mat_index(scene, (long)scene->figures[i].mat)) < 0)
			return (ft_puterror(1, "problems finding material by id"));
		scene->figures[i].mat = &(scene->materials[index]);
		i++;
	}
	return (0);
}

static void
*scene_free_null(t_scene *scene, int ecode, char *msg)
{
	scene_free(scene);
	return (ft_puterr_null(ecode, msg));
}

t_scene
*scene_from_file(char *filename)
{
	t_scene		*scene;
	char		*file_text;

	scene = scene_init();
	if (scene == NULL)
		ft_puterr_null(1, "Cannot init scene");
	comments_delete((file_text = ft_file_read(filename)));
	if (file_text == NULL)
		return (scene_free_null(scene, 2, "Cannot get text from file"));
	if (scene_parse(file_text, scene) < 0)
	{
		ft_free(file_text);
		return (scene_free_null(scene, 3, "Cannot parse scene from file"));
	}
	ft_free(file_text);
	if (scene_link_ids(scene) < 0)
		return (scene_free_null(scene, 4, "Cannot link resource ids"));
	ft_putstr_free(scene_to_str(scene));
	return (scene);
}
