/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:44:14 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/15 22:44:16 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->type = 0;
}

int			parse_flags(t_flags *flags, const char *str, int i)
{
	init_flags(flags);
	if (!is_type(str[i]))
	{
		i = parse_zero_minus(flags, str, i);
		i = parse_width(flags, str, i);
		i = parse_precision(flags, str, i);
	}
	if (is_type(str[i]))
	{
		flags->type = str[i];
		i++;
	}
	return (i);
}

int			is_type(char letter)
{
	if (letter == 'c' || letter == 's' || letter == 'p' || letter == 'd'
		|| letter == 'i' || letter == 'u' || letter == 'x' || letter == 'X' ||
		letter == '%')
		return (1);
	else
		return (0);
}
