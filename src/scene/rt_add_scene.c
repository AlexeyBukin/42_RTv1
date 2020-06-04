/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:18:15 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 02:59:42 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int
scene_add_component(char **text, t_scene *scene)
{
	if (text == NULL || scene == NULL)
		return (ft_puterror(1, "Null pointers entered"));
	if (*text == NULL)
		return (ft_puterror(2, "Dereference to NULL pointer"));
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
	else if (ft_str_next_is(*text, KEYWORD_CAMERA))
		return (scene_add_camera(scene, text));
	return (ft_puterror(3, "Expected known keywords"));
}


static int
scene_parse(char *text, t_scene *scene)
{
	t_bool		expect_next;

	if (text == NULL || scene == NULL)
		return (ft_puterror(1, "Null pointers entered"));
	if (*text != '{')
		return (ft_puterror(2, "Expected \'{\'"));
	text++;
	expect_next = TRUE;
	while (expect_next)
	{
		if (scene_add_component(&text, scene) < 0)
			return (ft_puterror(3, "Cannot add component to scene"));
		expect_next = read_comma(&text);
	}
	if (ft_strcmp(text, "}") != 0)
		return (ft_puterror(4, "Expected \'}\' and EOF"));
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

int
rt_read_scene(t_scene *scene, char *filename)
{
	char		*file_text;

	if (scene == NULL || filename == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if (scene_set_default(scene) < 0)
		return (ft_puterror(1, "Cannot init scene"));
	scene->filename = filename;
	file_text = comments_delete((ft_read_file(filename)));
	if (file_text == NULL)
		return (ft_puterror(2, "Cannot get text from file"));
	if (scene_parse(file_text, scene) < 0)
	{
		ft_free(file_text);
		return (ft_puterror(4,"Cannot parse scene from file"));
	}
	ft_free(file_text);
	if (scene_link_ids(scene) < 0)
		return (ft_puterror(4, "Cannot link resource ids"));

	//TODO delete debug symbols
	ft_putstr_free(scene_to_str(scene));
	return (0);
}

int
rt_add_scene(t_rt *rt, char *filename)
{
	if (rt == NULL)
		return (ft_puterror(1,"rt is NULL pointer"));
	rt->scenes = (t_scene*)ft_realloc_arr(rt->scenes, rt->scene_num,
								rt->scene_num + 1, sizeof(t_scene));
	if (rt->scenes == NULL)
		return (ft_puterror(2,"Realloc scenes returned NULL"));
	if (rt_read_scene(&(rt->scenes[rt->scene_num]), filename) < 0)
		return (ft_puterror(3, "Cannot read scene"));
	rt->scene_num++;
	return (0);
}
