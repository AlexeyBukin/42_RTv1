/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/03/26 14:20:44 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	after_taking(int *flags, int *all_byte, t_stg resolved, int *i)
{
	int		len;

	if (i == NULL || flags == NULL || all_byte == NULL)
		return ;
	if (resolved.taken > 0)
	{
		if (flags[C_GOT_NULL] == NULL_IN_THE_BEGINNING)
		{
			write(1, "", 1);
			(*all_byte)++;
		}
		len = (int)ft_strlen(resolved.string);
		(*all_byte) += len;
		write(1, resolved.string, len);
		free(resolved.string);
		if (flags[C_GOT_NULL] == NULL_IN_THE_END)
		{
			write(1, "", 1);
			(*all_byte)++;
		}
		*i += resolved.taken;
	}
}

void	write_from_buf(char *buf, size_t *buf_len)
{
	if (buf == NULL || buf_len == NULL)
		return ;
	write(1, buf, *buf_len);
	*buf_len = 0;
}

void	update_buf(size_t *buf_len, char **buf, char *stg_i, int *all_byte)
{
	if (buf_len == NULL || buf == NULL || stg_i == NULL || all_byte == NULL)
		return ;
	if (*buf_len == 0)
	{
		*buf = stg_i;
	}
	(*buf_len)++;
	if (stg_i[0] == '\n')
	{
		write(1, *buf, *buf_len);
		*buf_len = 0;
	}
	(*all_byte)++;
}

t_data	init(char *str)
{
	t_data	my_data;

	my_data.all_byte = 0;
	my_data.string = str;
	my_data.buf = my_data.string;
	my_data.buf_len = 0;
	return (my_data);
}

int		ft_printf(const char *format, ...)
{
	int		flags[FLAGS_LEN];
	t_stg	resolved;
	va_list	arg;
	t_data	d;
	int		i;

	va_start(arg, format);
	d = init((char *)format);
	i = -1;
	va_start(arg, format);
	while ((d.string)[++i] != '\0')
	{
		if ((d.string)[i] == '%')
		{
			write_from_buf(d.buf, &(d.buf_len));
			resolved = ft_resolve_arg(&((d.string)[i + 1]), arg, flags);
			after_taking(flags, &(d.all_byte), resolved, &i);
		}
		else
			update_buf(&(d.buf_len), &(d.buf), &((d.string)[i]), &(d.all_byte));
	}
	write(1, d.buf, d.buf_len);
	va_end(arg);
	return (d.all_byte);
}
