/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:14:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/01 18:46:10 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		texture_put_pixel(t_texture *texture, t_color col, size_t x, size_t y)
{
	size_t		offset;

	if (texture == NULL)
		return ;
	if (texture->img == NULL)
		return ;
	if (x >= texture->size_x || y >= texture->size_y)
	{
		ft_putendl("warning: trying to put pixel outside of texture");
		return ;
	}
	offset = y * texture->size_x * 4 + x * 4;
	texture->img[offset + 0] = col.b;
	texture->img[offset + 1] = col.g;
	texture->img[offset + 2] = col.r;
	texture->img[offset + 3] = col.a;
}

void		texture_fill(t_texture *texture, t_color col)
{
	int			offset;
	size_t		i;
	size_t		j;

	if (texture == NULL)
		return ;
	if (texture->img == NULL)
		return ;
	i = 0;
	while (i < texture->size_y)
	{
		j = 0;
		while (j < texture->size_x)
		{
			offset = i * texture->size_x * 4 + j * 4;
			texture->img[offset + 0] = col.b;
			texture->img[offset + 1] = col.g;
			texture->img[offset + 2] = col.r;
			texture->img[offset + 3] = col.a;
			j++;
		}
		i++;
	}
}

t_texture	*texture_create(size_t w, size_t h)
{
	t_texture	*texture;

	if ((texture = (t_texture*)malloc(sizeof(t_texture))) == NULL)
		return (ft_puterr_null(1, "texture_create(): cannot malloc texture struct"));
	if ((texture->img = (t_byte*)malloc(sizeof(t_byte) * w * h * 4)) == NULL)
		return (ft_puterr_null(2, "texture_create(): cannot malloc texture image"));
	texture->size_x = w;
	texture->size_y = h;
	texture_fill(texture, color(0, 0, 0));
	return (texture);
}
