/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 01:12:12 by hush              #+#    #+#             */
/*   Updated: 2020/05/22 16:49:16 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Reads file to one string
** Returns non-zero if error
*/

static int 		ft_looped(char **str, char *buf, int val)
{
	char 	*old;

	if (str == NULL)
		return (-1);
	buf[val] = '\0';
	old = *str;
	*str = ft_str_add(*str, buf);
	if (*str == NULL)
	{
		free(old);
		return (-1);
	}
	return (0);
}

char 			*ft_file_read(char *filename)
{
	int				fd;
	char 			*str;
	int				val;
	char			buf[BUFF_SIZE + 1];

	str = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0 || fd > 65535)
		return (NULL);
	while ((val = read(fd, buf, BUFF_SIZE)) > 0)
		if (ft_looped(&str, buf, val) < 0)
		{
			close(fd);
			return (NULL);
		}
	close(fd);
	if (val < 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
