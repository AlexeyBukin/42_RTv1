/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:32:26 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 19:11:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *s, char c)
{
	int		wc;
	int		i;
	int		last_delim;

	last_delim = 1;
	i = 0;
	wc = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			last_delim = 1;
		}
		else
		{
			if (last_delim == 1)
			{
				wc++;
			}
			last_delim = 0;
		}
		i++;
	}
	return (wc);
}
