/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:34:32 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/16 00:34:34 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type_c(t_flags flags, char c)
{
	int	i;

	i = 1;
	if (flags.minus)
		ft_putchar(c);
	if (flags.width)
	{
		if (flags.zero && !flags.minus)
			while (i != flags.width && i++)
				ft_putchar('0');
		else
			while (i != flags.width && i++)
				ft_putchar(' ');
	}
	if (!flags.minus)
		ft_putchar(c);
	return (i);
}
