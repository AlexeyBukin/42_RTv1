/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:14:45 by kcharla           #+#    #+#             */
/*   Updated: 2020/04/16 19:03:26 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** create and fill scene
*/

t_scene		*scene_create(void)
{
	t_scene		*scene;

	if ((scene = (t_scene*)malloc(sizeof(t_scene))) == NULL)
		return (ft_puterr_null(1, "scene_create():"
								  "cannot malloc scene struct"));
	scene->func_trace_dot[FIG_SPHERE] = trace_sphere;
	scene->func_trace_dot[FIG_PLANE] = trace_plane;
	scene->func_trace_dot[FIG_CYLINDER] = trace_cyl;

	scene->func_trace_bounce[FIG_SPHERE] = trace_sphere_bounce;
	scene->func_trace_bounce[FIG_PLANE] = trace_plane_bounce;
	return (scene);
}

t_scene		*scene_default_0(void)
{
	t_scene		*scene;

	if ((scene = scene_create()) == NULL)
		return (ft_puterr_null(1, "scene_default():"
		"cannot create scene"));

    if ((scene->figures = fig_arr_create(6)) == NULL)
        return (ft_puterr_null(1, "scene_default():"
                                  "cannot malloc figures array"));
    scene->figures[0] = (t_base_fig*)fig_plane_create(vec(0, 1, 0), 3.0, color(100, 100, 0));
    scene->figures[1] = (t_base_fig*)fig_plane_create(vec(0, -1, 0), 3.0, color(100, 0, 0));
    scene->figures[2] = (t_base_fig*)fig_plane_create(vec(0, 0, 1), 3.0, color(0, 100, 0));
    scene->figures[3] = (t_base_fig*)fig_plane_create(vec(0, 0, -1), 5.0, color(0, 100, 100));
    scene->figures[4] = (t_base_fig*)fig_plane_create(vec(-1, 0, 0), 20.0, color(100, 100, 100));

    scene->figures[5] = (t_base_fig*)fig_sphere_create(dot(5, 1, 1), 1.0, color(100, 0, 100));

//    scene->figures[5] = (t_base_fig*)fig_sphere_create();
//    scene->figures[6] = (t_base_fig*)fig_cyl_create();


	if ((scene->lights = light_arr_create(1)) == NULL)
		return (ft_puterr_null(1, "scene_default():"
		"cannot malloc lights array"));
	scene->lights[0] = light_create();
	return (scene);
}

t_scene		*scene_default_1(void)
{
	t_scene		*scene;

	if ((scene = scene_create()) == NULL)
		return (ft_puterr_null(1, "scene_default():"
								  "cannot create scene"));

	if ((scene->figures = fig_arr_create(4)) == NULL)
		return (ft_puterr_null(1, "scene_default():"
								  "cannot malloc figures array"));
	scene->figures[0] = (t_base_fig*)fig_plane_create(vec(0, 0, 1), 3.0, color(0, 100, 0));
	scene->figures[1] = (t_base_fig*)fig_plane_create(vec(-1, 0, 0), 20.0, color(100, 100, 100));

	scene->figures[2] = (t_base_fig*)fig_sphere_create(dot(5, 1, 1), 1.0, color(100, 0, 100));
	scene->figures[3] = (t_base_fig*)fig_sphere_create(dot(9, -1, 1), 1.0, color(100, 0, 0));

//    scene->figures[5] = (t_base_fig*)fig_sphere_create();
//    scene->figures[6] = (t_base_fig*)fig_cyl_create();


	if ((scene->lights = light_arr_create(1)) == NULL)
		return (ft_puterr_null(1, "scene_default():"
								  "cannot malloc lights array"));
	scene->lights[0] = light_create();
	return (scene);
}

/*
** TODO add plane to scene
*/

int	 		scene_manage_plane(t_scene *scene, char *line)
{
	t_vec		n;
	double		d;
	size_t		i;

	i = 0;
	while (ft_is_blank(line[i]))
		i++;
	n.x = ft_atod(&line[i]);
	while ((line[i] <= '9' && line[i] >= '0') || line[i] == '.')
		i++;
	while (ft_is_blank(line[i]))
		i++;
	n.y = ft_atod(&line[i]);
	while ((line[i] <= '9' && line[i] >= '0') || line[i] == '.')
		i++;
	while (ft_is_blank(line[i]))
		i++;
	n.z = ft_atod(&line[i]);
	while ((line[i] <= '9' && line[i] >= '0') || line[i] == '.')
		i++;
	while (ft_is_blank(line[i]))
		i++;
	d = ft_atod(&line[i]);
	(void)scene;
	return (-1);
}

int	 		scene_manage_line(t_scene *scene, char *line)
{
	size_t		i;

	if (scene == NULL || line == NULL)
		return (ft_puterror(1, "nullptr"));
	if (line[0] == '#')
		return (0);
	i = 0;
	while (ft_is_blank(line[i]))
		i++;
	if (ft_strncmp(&line[i], "plane ", 6) == 0)
	{
		return (scene_manage_plane(scene, &(line[i+6])));
	}
//	if (ft_strncmp(&line[i], "sphere ", 6) == 0)
//	{
//		return (scene_manage_sphere(scene, &(line[i+6])));
//	}
//	if (ft_strncmp(&line[i], "cyl ", 6) == 0)
//	{
//		return (scene_manage_cyl(scene, &(line[i+6])));
//	}
//	if (ft_strncmp(&line[i], "cone ", 6) == 0)
//	{
//		return (scene_manage_cone(scene, &(line[i+6])));
//	}
	return (ft_puterror(1, "unknown scene command"));
}

t_scene		*scene_read(char *filename)
{
	char		*line;
	int			fd;
	t_scene		*scene;

	if ((scene = scene_create()) == NULL)
		return (ft_puterr_null(1, "scene_read():"
								  "cannot create scene"));
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (scene_manage_line(scene, line) < 0)
		{
			free(line);
			return (ft_puterr_null(1, "scene_read():"
									  "unknown line"));
		}
		free(line);
	}
	free(line);
	close(fd);
	return (scene);
}