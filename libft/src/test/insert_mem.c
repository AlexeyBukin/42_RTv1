/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:30:58 by lmelina           #+#    #+#             */
/*   Updated: 2020/01/31 15:38:47 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** TODO эти функции
*/

/*
** void *memory, void *insertion, size_t index, size_t inslen, size_t memlen)
*/

void	*ft_insert_mem(void *memory, void *ins, size_t index, size_t inslen)
{
	uint8_t	*result;
	uint8_t	*mem;
	uint8_t	*insert;
	int		i;

	mem = (uint8_t*)memory;
	insert = (uint8_t*)ins;
	result = (uint8_t*)malloc(sizeof(uint8_t) * (inslen + 2));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < (int)index)
		result[i] = mem[i];
	i++;
	while (i < (int)(index + inslen))
	{
		result[i] = insert[i - index];
		i++;
	}
	while (i < (int)(2 + inslen))
	{
		result[i] = mem[i - inslen];
		i++;
	}
	return (result);
}
