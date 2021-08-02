/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:42:53 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/16 00:42:56 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_zero(int flag, unsigned int n, int size, int reg)
{
	int	len;

	len = 0;
	while ((len + size) != flag)
	{
		ft_putchar('0');
		++len;
	}
	ft_putnbr_hex(n, reg);
	return (size + len);
}

static int	print_precision(t_flags flags, unsigned int n, int size, int reg)
{
	int	len;

	len = 0;
	if (flags.minus && size != 0)
		size = print_with_zero(flags.precision, n, size, reg);
	if (flags.width)
		while ((len + flags.precision) != flags.width)
		{
			ft_putchar(' ');
			++len;
		}
	if (!flags.minus && size != 0)
		size = print_with_zero(flags.precision, n, size, reg);
	return (size + len);
}

static int	print_width(t_flags flags, unsigned int n, int size, int reg)
{
	if (flags.zero && !flags.minus)
		size = print_with_zero(flags.width, n, size, reg);
	else
	{
		if (flags.minus)
			ft_putnbr_hex(n, reg);
		while (size != flags.width)
		{
			ft_putchar(' ');
			++size;
		}
		if (!flags.minus)
			ft_putnbr_hex(n, reg);
	}
	return (size);
}

int			print_type_x(t_flags flags, unsigned int n, int reg)
{
	int	size;

	size = ft_count(n, 16);
	if (flags.precision <= size && flags.precision != -1)
	{
		if (flags.precision == 0 && n == 0)
			return (print_precision(flags, 0, 0, reg));
		flags.zero = 0;
		flags.precision = -1;
	}
	if (flags.width <= flags.precision || flags.width <= size)
		flags.width = 0;
	if (flags.width == 0 && flags.precision == -1)
	{
		ft_putnbr_hex(n, reg);
		return (size);
	}
	else if (flags.width && flags.precision == -1)
		return (print_width(flags, n, size, reg));
	else
		return (print_precision(flags, n, size, reg));
}
