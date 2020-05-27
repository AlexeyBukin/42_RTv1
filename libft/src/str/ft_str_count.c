/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 02:56:01 by hush              #+#    #+#             */
/*   Updated: 2020/05/04 02:56:01 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_str_count(const char *text, const char *word)
{
	size_t		wlen;
	size_t		count;

	if (text == NULL || word == NULL)
		return (0);
	count = 0;
	wlen = ft_strlen(word);
	if (wlen < 1)
		return (0);
	while ((text = ft_strstr(text, word)) != NULL)
	{
		count++;
		text += wlen;
	}
	return (count);
}