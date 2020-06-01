/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 12:01:54 by hush              #+#    #+#             */
/*   Updated: 2020/06/01 02:31:51 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num		read_num(char **source)
{
	t_num		res;
	char		*ptr;

	if (source == NULL)
		return ((t_num)INFINITY);
	if ((ptr = *source) == NULL)
		return ((t_num)INFINITY);
	res = (t_num)ft_atod(ptr);
	while (*ptr != '\0' && ft_isnum(*ptr))
		ptr++;
	*source = ptr;
	return (res);
}
