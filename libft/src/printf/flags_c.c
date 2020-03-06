/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:39:52 by lmelina           #+#    #+#             */
/*   Updated: 2020/03/06 03:10:00 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_c(va_list arg, int *flags)
{
	char val;
	char *spammed;
	char *character;

	val = (char)va_arg(arg, int);
	if (flags[WIDTH] <= 0)
		flags[WIDTH] = 1;
	spammed = ft_str_spam(" ", flags[WIDTH] - 1);
	if (val != 0)
	{
		if ((character = ft_strdup("*")) != NULL)
			character[0] = val;
	}
	else
	{
		character = ft_strdup("");
		flags[WIDTH] = 0;
		flags[C_GOT_NULL] = (flags[MINUS] == 1) ? 1 : 2;
	}
	if (flags[MINUS] == 1)
		character = ft_strjoin_free(character, spammed);
	else
		character = ft_strjoin_free(spammed, character);
	return (character);
}
