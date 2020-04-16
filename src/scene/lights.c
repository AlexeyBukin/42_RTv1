/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:37:12 by hush              #+#    #+#             */
/*   Updated: 2020/04/16 19:01:18 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*light_create(void)
{
	t_light		*light;

	light = (t_light*)malloc(sizeof(t_light));
	if (light != NULL)
    {
	    light->point.pos = dot(0, 0, 4);
	    light->point.col = color(255, 255, 255);
	    light->point.power = 100.0;
    }
	return (light);
}

t_light		**light_arr_create(size_t num)
{
	t_light		**light_arr;

	if (num > SIZE_MAX / sizeof (t_light*) - 1)
		return (NULL);
	light_arr = (t_light**)malloc(sizeof(t_light*) * (num + 1));
	if (light_arr != NULL)
    {
	    light_arr[num] = NULL;
    }
	return (light_arr);
}

int				light_destroy(t_light *light)
{
	free(light);
	return (OK);
}

int				light_arr_destroy(t_light **light_arr)
{
	size_t		i;

	if (light_arr == NULL)
		return (ft_puterror(1, "fig_arr_destroy():"
								  " fig_arr is NULL"));
	i = 0;
	while (light_arr[i] != NULL)
	{
		light_destroy(light_arr[i]);
	}
	free(light_arr);
	return (OK);
}
