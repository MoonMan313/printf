/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:42:17 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/16 00:43:00 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_width(t_flags flags, unsigned long long int n, int size)
{
	if (flags.minus)
	{
		ft_putstr("0x");
		ft_putnbr_hex(n, 0);
	}
	while (size != flags.width)
	{
		ft_putchar(' ');
		++size;
	}
	if (!flags.minus)
	{
		ft_putstr("0x");
		ft_putnbr_hex(n, 0);
	}
	return (size);
}

int			print_type_p(t_flags flags, unsigned long long int p)
{
	int	size;

	size = ft_count_u(p, 16) + 2;
	if (flags.width <= size)
		flags.width = 0;
	if (flags.width == 0)
	{
		ft_putstr("0x");
		ft_putnbr_hex(p, 0);
		return (size);
	}
	else
		return (print_width(flags, p, size));
}
