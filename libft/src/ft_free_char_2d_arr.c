/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_2d_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:59:10 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/26 19:59:10 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_char_2d_arr(char ***input)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (input == 0)
		return ;
	arr = *input;
	if (arr == 0)
		return ;
	while (arr[i] != 0)
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
	free(arr);
	arr = NULL;
}
