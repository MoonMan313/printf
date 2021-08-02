/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:44:02 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/16 00:44:04 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_zero(int flag, unsigned int n, int size)
{
	int	len;

	len = 0;
	while ((len + size) != flag)
	{
		ft_putchar('0');
		++len;
	}
	ft_putnbr(n);
	return (size + len);
}

static int	print_precision(t_flags flags, unsigned int n, int size)
{
	int	len;

	len = 0;
	if (flags.minus && size != 0)
		size = print_with_zero(flags.precision, n, size);
	if (flags.width)
		while ((len + flags.precision) != flags.width)
		{
			ft_putchar(' ');
			++len;
		}
	if (!flags.minus && size != 0)
		size = print_with_zero(flags.precision, n, size);
	return (size + len);
}

static int	print_width(t_flags flags, unsigned int n, int size)
{
	if (flags.zero && !flags.minus)
		size = print_with_zero(flags.width, n, size);
	else
	{
		if (flags.minus)
			ft_putnbr(n);
		while (size != flags.width)
		{
			ft_putchar(' ');
			++size;
		}
		if (!flags.minus)
			ft_putnbr(n);
	}
	return (size);
}

int			print_type_u(t_flags flags, unsigned int n)
{
	int	size;

	size = ft_count_u(n, 10);
	if (flags.precision <= size && flags.precision != -1)
	{
		if (flags.precision == 0 && n == 0)
			return (print_precision(flags, 0, 0));
		flags.zero = 0;
		flags.precision = -1;
	}
	if (flags.width <= flags.precision || flags.width <= size)
		flags.width = 0;
	if (flags.width == 0 && flags.precision == -1)
	{
		ft_putnbr(n);
		return (size);
	}
	else if (flags.width && flags.precision == -1)
		return (print_width(flags, n, size));
	else
		return (print_precision(flags, n, size));
}
