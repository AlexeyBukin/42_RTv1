/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:26:49 by lmelina           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stg	ft_resolve_arg(char *string, va_list arg, int *flags)
{
	int		len;

	len = arg_len(string);
	if (parse_flags(string, len, flags) < 0)
		return ((t_stg) {NULL, -1});
	string = NULL;
	if (flags[FLAG] == 's')
		string = ft_insert_s(arg, flags);
	else if (flags[FLAG] == 'c')
		string = ft_insert_c(arg, flags);
	else if (flags[FLAG] == 'd' || flags[FLAG] == 'i')
		string = ft_insert_d(arg, flags);
	else if (flags[FLAG] == 'u')
		string = ft_insert_u(arg, flags);
	else if (flags[FLAG] == 'p')
		string = ft_insert_p(arg, flags);
	else if (flags[FLAG] == 'o')
		string = ft_insert_o(arg, flags);
	else if (flags[FLAG] == 'x' || flags[FLAG] == 'X')
		string = ft_insert_x(arg, flags, flags[FLAG] == 'X');
	else if (flags[FLAG] == 'f' || flags[FLAG] == 'F')
		string = ft_float(arg, flags);
	else if (flags[FLAG] == '%')
		string = ft_insert_percentage(flags);
	return ((t_stg) {string, (string == NULL) ? -1 : len});
}
