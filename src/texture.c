/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:14:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/17 00:51:22 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	texture_put_pixel(t_texture texture, t_color col, size_t x, size_t y)
{
	size_t		offset;

	if (texture.img == NULL)
		return ;
	offset = y * texture.size_x * 4 + x * 4;
	texture.img[offset + 0] = col.r;
	texture.img[offset + 1] = col.g;
	texture.img[offset + 2] = col.b;
	texture.img[offset + 3] = col.a;
}

void	texture_fill(t_texture texture, t_color col)
{
	int			offset;
	size_t		i;
	size_t		j;

	if (texture.img == NULL)
		return ;
	i = 0;
	while (i < texture.size_y)
	{
		j = 0;
		while (j < texture.size_x)
		{
			offset = i * texture.size_x * 4 + j * 4;
			texture.img[offset + 0] = col.r;
			texture.img[offset + 1] = col.g;
			texture.img[offset + 2] = col.b;
			texture.img[offset + 3] = col.a;
			j++;
		}
		i++;
	}
}

int		texture_init(t_texture *texture, size_t w, size_t h)
{
	if (texture == NULL)
		return (ft_puterror(1, "texture_init(): texture_init pointer is NULL"));
	if (((*texture).img = (t_byte*)malloc(sizeof(t_byte) * w * h * 4)) == NULL)
		return (ft_puterror(3, "texture_init(): cannot malloc texture"));
	(*texture).size_x = w;
	(*texture).size_y = h;
	return (0);
}
