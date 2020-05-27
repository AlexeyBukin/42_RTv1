/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_comma.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 12:04:08 by hush              #+#    #+#             */
/*   Updated: 2020/05/23 12:04:08 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool		read_comma(char **str)
{
	t_bool		is_comma;
	char		*ptr;

	if (str == NULL)
		return (FALSE);
	if ((ptr = *str) == NULL)
		return (FALSE);
	is_comma = (t_bool) (*ptr == ',');
	if (is_comma)
		(*str)++;
	return (is_comma);
}
