/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:01:24 by hush              #+#    #+#             */
/*   Updated: 2020/03/06 03:10:00 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct		s_color
{
	t_byte			r;
	t_byte			g;
	t_byte			b;
	t_byte			a;
}					t_color;

/*
** color.c
*/

t_color				col_mask(t_color col, t_color mask);
t_color				color_alpha(t_byte r, t_byte g, t_byte b, t_byte a);
t_color				color(t_byte red, t_byte green, t_byte blue);
t_color				color_add(t_color a, t_color b);
t_color				color_from_int(int src);
int					color_to_int(t_color col);
char				*color_to_str(t_color color);
char				*color_to_str_color(t_color color);

#endif
