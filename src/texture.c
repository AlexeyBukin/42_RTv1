/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:14:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/23 21:35:08 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		texture_put_pixel(t_texture *tex, t_col col, size_t x, size_t y)
{
	size_t		offset;

	if (tex == NULL)
		return ;
	if (tex->img == NULL)
		return ;
	if (x >= tex->size_x || y >= tex->size_y)
	{
		ft_putendl("warning: trying to put pixel outside of texture");
		return ;
	}
	offset = y * tex->size_x * 4 + x * 4;
	tex->img[offset + 0] = col.b;
	tex->img[offset + 1] = col.g;
	tex->img[offset + 2] = col.r;
	tex->img[offset + 3] = col.a;
}

void		texture_fill(t_texture *texture, t_col col)
{
	size_t		offset;
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

t_texture	*texture_init(size_t w, size_t h)
{
	t_texture	*texture;

	if ((texture = (t_texture*)ft_malloc(sizeof(t_texture))) == NULL)
		return (ft_puterr_null(1, "texture_create():"
		"cannot malloc texture struct"));
	texture->img = (t_byte*)ft_malloc(sizeof(t_byte) * w * h * 4);
	if ((texture->img) == NULL)
		return (ft_puterr_null(2, "texture_create():"
		" cannot malloc texture image"));
	texture->size_x = w;
	texture->size_y = h;
	texture_fill(texture, col(0, 0, 0));
	return (texture);
}

void		texture_free(t_texture *texture)
{
	if (texture == NULL)
		return ;
	ft_free(texture->img);
	ft_free(texture);
}
