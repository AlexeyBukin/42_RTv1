/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_texture_s.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 03:17:19 by hush              #+#    #+#             */
/*   Updated: 2020/06/04 03:17:19 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TEXTURE_S_H
# define RT_TEXTURE_S_H

typedef struct		s_texture
{
	size_t			size_x;
	size_t			size_y;
	t_byte			*img;
}					t_texture;

#endif