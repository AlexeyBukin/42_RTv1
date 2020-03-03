/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:39:29 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/03 20:53:23 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_base_fig		*fig_create(void)
{
	t_base_fig		*fig;

	fig = (t_base_fig*)malloc(sizeof(t_base_fig));
	return (fig);
}

t_base_fig		**fig_arr_create(size_t num)
{
	t_base_fig		**fig_arr;

	if (num > SIZE_MAX / sizeof (t_base_fig*) - 1)
		return (NULL);
	fig_arr = (t_base_fig**)malloc(sizeof(t_base_fig*) * ++num);
	return (fig_arr);
}

int				fig_destroy(t_base_fig *fig)
{
	free(fig);
	return (OK);
}

int				fig_arr_destroy(t_base_fig **fig_arr)
{
	size_t		i;

	if (fig_arr == NULL)
		return (ft_puterror(1, "fig_arr_destroy():"
								  " fig_arr is NULL"));
	i = 0;
	while (fig_arr[i] != NULL)
	{
		fig_destroy(fig_arr[i]);
	}
	free(fig_arr);
	return (OK);
}
