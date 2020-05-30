/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:42:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/05/29 18:22:31 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			main(int ac, char **args)
{
	t_rt		*rtv1;

	if ((rtv1 = rtv1_init(ac, args)) == NULL)
	{
		rtv1_quit(rtv1);
		return (ft_puterror(1, "main(): rtv1_init() returned NULL"));
	}
	if (rt_loop(rtv1) < 0)
	{
		rtv1_quit(rtv1);
		return (ft_puterror(2, "main(): problems running rtv1_loop()"));
	}
	rtv1_quit(rtv1);
	return (0);
}
