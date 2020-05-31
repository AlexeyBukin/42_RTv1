/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_s.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:23:16 by hush              #+#    #+#             */
/*   Updated: 2020/05/30 16:28:42 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_S_H
# define RT_UTILS_S_H

# include "libft.h"
# include "rt_vector_s.h"

typedef struct		s_color
{
	t_byte			r;
	t_byte			g;
	t_byte			b;
	t_byte			a;
}					t_col;

typedef	struct		s_ray
{
	t_vec			pos;
	t_vec			dir;
}					t_ray;

#endif
