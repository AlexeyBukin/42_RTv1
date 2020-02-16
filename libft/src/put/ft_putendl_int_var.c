/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_int_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:20:16 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/06 20:20:16 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_int_var(const char *var_name, int var)
{
	ft_putstr_free(ft_strjoin(var_name, ": "));
	ft_putendl_free(ft_itoa(var));
}
