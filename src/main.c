/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:42:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/04 16:43:53 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			main(int ac, char **args)
{
	t_rt		*rt;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return (ft_puterror(1, "main(): cannot init SDL"));
	}
	if ((rt = rt_new(ac, args)) == NULL)
	{
		rt_quit(rt);
		return (ft_puterror(2, "main(): rtv1_init() returned NULL"));
	}
	if (rt_loop(rt) < 0)
	{
		rt_quit(rt);
		return (ft_puterror(3, "main(): problems running rtv1_loop()"));
	}
	rt_quit(rt);
	return (0);
}
