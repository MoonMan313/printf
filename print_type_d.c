/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:43:42 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/16 00:43:44 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_zero(int flag, int n, int size)
{
	int	len;

	len = 0;
	if (n < 0 && ++len)
		ft_putchar('-');
	while ((len + size) != flag && ++len)
		ft_putchar('0');
	if (n < 0)
		ft_putnbr((-1) * n);
	else
		ft_putnbr(n);
	return (size + len);
}

static int	print_precision(t_flags flags, int n, int size)
{
	int	len;

	len = 0;
	if (n < 0)
		flags.precision++;
	if (flags.minus && size != 0)
		size = print_with_zero(flags.precision, n, size);
	if (flags.width)
		while ((len + flags.precision) != flags.width && ++len)
			ft_putchar(' ');
	if (!flags.minus && size != 0)
		size = print_with_zero(flags.precision, n, size);
	return (size + len);
}

static int	print_width(t_flags flags, int n, int size)
{
	if (flags.zero && !flags.minus)
		size = print_with_zero(flags.width, n, size);
	else
	{
		if (flags.minus)
			ft_putnbr(n);
		if (n < 0)
			size++;
		while (size != flags.width && size++)
			ft_putchar(' ');
		if (!flags.minus)
			ft_putnbr(n);
	}
	return (size);
}

int			print_type_di(t_flags flags, int n)
{
	int	size;

	size = ft_count(n, 10);
	if (flags.precision <= size && flags.precision > -1)
	{
		if (flags.precision == 0 && n == 0)
			return (print_precision(flags, 0, 0));
		flags.zero = 0;
		flags.precision = -1;
	}
	if (flags.width <= flags.precision || flags.width <= size)
		flags.width = 0;
	if (flags.width == 0 && flags.precision < 0)
	{
		ft_putnbr(n);
		return ((n >= 0) ? size : (size + 1));
	}
	else if (flags.width && flags.precision < 0)
		return (print_width(flags, n, size));
	else
		return (print_precision(flags, n, size));
}
