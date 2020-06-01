/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:29:28 by hush              #+#    #+#             */
/*   Updated: 2020/06/02 02:27:06 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		read_id(char **source, size_t *id_field)
{
	long long	res;
	char		*text;

	if (source == NULL || id_field == NULL)
		return (ft_puterror(1, "Entered NULL pointers"));
	if ((text = *source) == NULL)
		return (ft_puterror(2, "Entered NULL pointers"));
	if (*text != '[')
		return (0);
	text++;
	res = (long long)read_num(&text);
	if (res < 0)
		return (ft_puterror(3, "Syntax error: expected correct id"));
	*id_field = res;
	if (*text != ']')
		return (ft_puterror(4, "Syntax error: Expected \']\'"));
	text++;
	*source = text;
	return (0);
}
