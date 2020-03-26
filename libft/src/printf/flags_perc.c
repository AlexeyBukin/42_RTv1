/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:09:48 by lmelina           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_percentage(int *flags)
{
	char	*perc;
	int		len;

	perc = ft_strdup("%");
	if (flags[ZERO] == 1 && flags[PRECISION] == 0 && flags[MINUS] == 0)
	{
		len = (int)ft_strlen(perc);
		if (flags[PLUS] == 1 || flags[SPACE] == 1)
			len++;
		perc = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), perc);
	}
	if (flags[WIDTH] > 0 && (len = (int)ft_strlen(perc)) < flags[WIDTH])
	{
		if (flags[MINUS] == 1)
		{
			perc = ft_strjoin_free(perc, ft_str_spam(" ", flags[WIDTH] - len));
		}
		else
		{
			perc = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), perc);
		}
	}
	return (perc);
}
