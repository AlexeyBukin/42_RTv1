/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:44:30 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/22 18:13:25 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_free(void *p)
{
	free(p);
	return (0);
}

int			ft_free_2(void *p, void *p2)
{
	free(p);
	free(p2);
	return (0);
}

int			ft_free_3(void *p, void *p2, void *p3)
{
	free(p);
	free(p2);
	free(p3);
	return (0);
}

void		*ft_free_null(void *p)
{
	free(p);
	return (NULL);
}

void		*ft_free_2_null(void *p, void *p2)
{
	free(p);
	free(p2);
	return (NULL);
}

void		*ft_free_3_null(void *p, void *p2, void *p3)
{
	free(p);
	free(p2);
	free(p3);
	return (NULL);
}
