/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:42:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		rtv1_quit(t_rtv1 *rtv1)
{
	if (rtv1 != NULL)
		destroy_rtv1(rtv1);
	SDL_Quit();
}

int			main(void)
{
	t_rtv1	*rtv1;

	rtv1 = NULL;
	if (rtv1_init(&rtv1) < 0)
	{
		rtv1_quit(rtv1);
		return (ft_puterror(1, "main(): problems running rtv1_init()"));
	}
	if (rtv1_loop(rtv1) < 0)
	{
		rtv1_quit(rtv1);
		return (ft_puterror(2, "main(): problems running rtv1_loop()"));
	}
	rtv1_quit(rtv1);
	return (0);
}
