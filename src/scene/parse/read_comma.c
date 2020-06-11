/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_comma.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 12:04:08 by hush              #+#    #+#             */
/*   Updated: 2020/06/11 23:10:52 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		read_comma(char **str)
{
	if (str == NULL)
		return (ft_puterror(1, "Entered NULL pointer(s) "));
	if (*str == NULL)
		return (ft_puterror(2, "Dereference to NULL pointer(s) "));
	if (*(*str) != ',')
		return (-3);
	(*str)++;
	return (0);
}
