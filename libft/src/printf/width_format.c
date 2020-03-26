/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:53:01 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*width_format(int *flags, char *str, char sign)
{
	int len;
	int w;

	if (str == NULL || flags == NULL)
		return (NULL);
	len = (int)ft_strlen(str);
	w = flags[WIDTH] - (sign < 0 || flags[PLUS] == 1 || flags[SPACE] == 1);
	if (len < w)
	{
		if (flags[MINUS] == 0 && flags[ZERO] == 1)
			str = ft_strjoin_free(ft_str_spam("0", w - len), str);
		else if (flags[MINUS] != 0)
			str = ft_strjoin_free(str, ft_str_spam(" ", w - len));
	}
	if (flags[SPACE] == 1 && sign > 0 && flags[PLUS] == 0)
		str = ft_strjoin_free(ft_strdup(" "), str);
	if (sign < 0)
		str = ft_strjoin_free(ft_strdup("-"), str);
	else if (flags[PLUS] == 1)
		str = ft_strjoin_free(ft_strdup("+"), str);
	if (len < w && flags[MINUS] == 0 && flags[ZERO] == 0)
		str = ft_strjoin_free(ft_str_spam(" ", w - len), str);
	return (str);
}
