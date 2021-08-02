/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:18:59 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/15 14:19:01 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_zero_minus(t_flags *flags, const char *str, int i)
{
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			flags->minus = 1;
		else
			flags->zero = 1;
		i++;
	}
	return (i);
}

int		parse_width(t_flags *flags, const char *str, int i)
{
	char	*width;
	int		len;

	len = 0;
	while (ft_isdigit(str[i]))
	{
		len++;
		i++;
	}
	if (len > 0)
	{
		width = ft_substr(str, i - len, len);
		flags->width = ft_atoi(width);
		free(width);
	}
	if (str[i] == '*' && i++)
		flags->width = -2;
	return (i);
}

int		parse_precision(t_flags *flags, const char *str, int i)
{
	char	*width;
	int		len;

	len = 0;
	if (str[i] == '.' && i++ && str[i])
	{
		flags->precision = 0;
		while (ft_isdigit(str[i]))
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			width = ft_substr(str, i - len, len);
			flags->precision = ft_atoi(width);
			free(width);
		}
		if (str[i] == '*' && i++)
			flags->precision = -2;
	}
	return (i);
}

void	parse_star(t_flags *flags, va_list ap)
{
	if (flags->width == -2)
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
	}
	if (flags->precision == -2)
	{
		flags->precision = va_arg(ap, int);
	}
}
