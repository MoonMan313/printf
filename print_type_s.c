/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:44:28 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/16 00:44:33 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putstr_len(const char *s, int len)
{
	int		i;

	i = 0;
	while (s != 0 && s[i] && len != 0)
	{
		write(1, &s[i], 1);
		i++;
		len--;
	}
}

int			print_type_s(t_flags flags, const char *str)
{
	int		len;

	if (str == 0)
	{
		str = (char *)str;
		str = "(null)";
		len = 6;
	}
	else
		len = ft_strlen(str);
	if (flags.precision > -1 && flags.precision < len)
		len = flags.precision;
	else
		flags.precision = len;
	if (flags.minus)
		putstr_len(str, flags.precision);
	if (flags.width > flags.precision && flags.precision > -1)
		while (len != flags.width && ++len)
			ft_putchar(' ');
	if (!flags.minus)
		putstr_len(str, flags.precision);
	return (len);
}
