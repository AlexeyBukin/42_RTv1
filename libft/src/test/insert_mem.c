/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:30:58 by lmelina           #+#    #+#             */
/*   Updated: 2020/02/18 16:03:27 by kcharla          ###   ########.fr       */
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
	t_byte	*result;
	t_byte	*mem;
	t_byte	*insert;
	int		i;

	mem = (t_byte*)memory;
	insert = (t_byte*)ins;
	result = (t_byte*)malloc(sizeof(t_byte) * (inslen + 2));
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
