/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:20:44 by hush              #+#    #+#             */
/*   Updated: 2020/06/13 13:52:53 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		read_vec(char **source, t_vec *res)
{
	char		*text;

	if (source == NULL || res == NULL)
		return (ft_puterror(1, "Entered NULL pointers"));
	if ((text = *source) == NULL)
		return (ft_puterror(2, "Entered NULL pointers"));
	if (*text != '<')
		return (ft_puterror(3, "Syntax error: Expected \'<\'"));
	text++;
	res->x = read_num(&text);
	if (read_comma(&text) < 0)
		return (ft_puterror(4, "Syntax error: Expected \',\'"));
	res->y = read_num(&text);
	if (read_comma(&text) < 0)
		return (ft_puterror(5, "Syntax error: Expected \',\'"));
	res->z = read_num(&text);
	if (*text != '>')
		return (ft_puterror(6, "Syntax error: Expected \'>\'"));
	text++;
	if (vec_is_inf(*res))
		return (ft_puterror(7, "Parse error: vector is infinite"));
	*source = text;
	return (0);
}

int		read_vec_after_comma(char **source, t_vec *res)
{
	if (read_comma(source) < 0)
		return (ft_puterror(1, "Syntax error: expected \',\' "));
	if (read_vec(source, res) < 0)
		return (ft_puterror(2, "Syntax error: expected vector "));
	return (0);
}
