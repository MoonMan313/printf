/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:24:45 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/16 00:24:46 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(t_flags *flags, va_list ap)
{
	int	size;

	size = 0;
	parse_star(flags, ap);
	if (flags->type == '%')
		size += print_type_c(*flags, '%');
	if (flags->type == 'c')
		size += print_type_c(*flags, va_arg(ap, int));
	if (flags->type == 's')
		size += print_type_s(*flags, va_arg(ap, const char *));
	if (flags->type == 'p')
		size += print_type_p(*flags, va_arg(ap, unsigned long long int));
	if (flags->type == 'd' || flags->type == 'i')
		size += print_type_di(*flags, va_arg(ap, int));
	if (flags->type == 'u')
		size += print_type_u(*flags, va_arg(ap, unsigned int));
	if (flags->type == 'x')
		size += print_type_x(*flags, va_arg(ap, unsigned int), 0);
	if (flags->type == 'X')
		size += print_type_x(*flags, va_arg(ap, unsigned int), 1);
	return (size);
}
