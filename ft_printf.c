/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:38:24 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/13 18:38:27 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *str, va_list ap)
{
	t_flags	flags;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			i = parse_flags(&flags, str, i);
			size += print_type(&flags, ap);
		}
		else
		{
			write(1, &str[i], 1);
			size++;
			i++;
		}
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, format);
	size = print_str(format, ap);
	va_end(ap);
	return (size);
}
