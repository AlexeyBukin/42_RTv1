/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:29:28 by hush              #+#    #+#             */
/*   Updated: 2020/05/24 01:31:46 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

long		read_id(char **source)
{
	long 		res;
	char		*text;

	if (source == NULL)
		return (ft_puterror(1, "Entered NULL pointers"));
	if ((text = *source) == NULL)
		return (ft_puterror(2, "Entered NULL pointers"));
	if (*text != '[')
		return (0);
	text++;
	res = (long)read_num(&text);
	if (*text != ']')
		return (ft_puterror(6, "Syntax error: Expected \']\'"));
	text++;
	*source = text;
	return (res);
}
