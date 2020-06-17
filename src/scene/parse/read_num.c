/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 12:01:54 by hush              #+#    #+#             */
/*   Updated: 2020/06/13 13:52:53 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_num	read_num(char **source)
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

int		read_num_bound(char **source, t_num *num, t_num min, t_num max)
{
	if (source == NULL || num == NULL)
		return (ft_puterror(1, "Entered NULL pointer(s)"));
	*num = read_num(source);
	if (*num < min || *num > max)
		return (ft_puterror(2, "Number is out of bounds"));
	return (0);
}

int		read_num_after_comma(char **source, t_num *num)
{
	if (source == NULL || num == NULL)
		return (ft_puterror(1, "Entered NULL pointer(s)"));
	if (read_comma(source) < 0)
		return (ft_puterror(1, "Syntax error: expected \',\' "));
	*num = read_num(source);
	return (0);
}

int		read_num_bound_after_comma(char **src, t_num *n, t_num min, t_num max)
{
	if (src == NULL || n == NULL)
		return (ft_puterror(1, "Entered NULL pointer(s)"));
	if (read_comma(src) < 0)
		return (ft_puterror(1, "Syntax error: expected \',\' "));
	if (read_num_bound(src, n, min, max) < 0)
		return (ft_puterror(1, "Syntax error: expected correct number "));
	return (0);
}
