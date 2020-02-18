/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:23:49 by lmelina           #+#    #+#             */
/*   Updated: 2020/01/31 17:25:44 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_s3(int len, char *res, int *flags)
{
	if (flags[ZERO] == 1 && flags[PRECISION] == 0 && flags[MINUS] == 0)
	{
		len = (int)ft_strlen(res);
		if (len < flags[WIDTH])
			res = ft_strjoin_free(ft_str_spam("0", flags[WIDTH] - len), res);
	}
	if (flags[WIDTH] > 0 && (len = (int)ft_strlen(res)) < flags[WIDTH])
	{
		if (flags[MINUS] == 1)
			res = ft_strjoin_free(res, ft_str_spam(" ", flags[WIDTH] - len));
		else
			res = ft_strjoin_free(ft_str_spam(" ", flags[WIDTH] - len), res);
	}
	return (res);
}

char	*ft_insert_s2(char *insert, int *flags)
{
	char	*res;
	int		len;

	len = 0;
	if (insert == NULL)
	{
		if (flags[PRECISION] == -1)
			res = ft_strdup("");
		else
			res = ft_strdup("(null)");
		if (flags[PRECISION] < 6 && flags[PRECISION] != 0)
			res[flags[PRECISION]] = '\0';
	}
	else
	{
		len = (int)ft_strlen(insert);
		if (flags[PRECISION] < len && flags[PRECISION] != 0)
			insert[flags[PRECISION]] = '\0';
		if (flags[PRECISION] == -1)
			res = ft_strdup("");
		else
			res = ft_strdup(insert);
		free(insert);
	}
	return (ft_insert_s3(len, res, flags));
}

char	*ft_insert_s(va_list arg, int *flags)
{
	char *insert;

	insert = va_arg(arg, char*);
	if (insert != NULL)
		insert = ft_strdup(insert);
	return (ft_insert_s2(insert, flags));
}
