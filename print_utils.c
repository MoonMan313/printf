/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_basic_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:44:05 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/13 18:44:11 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(int c)
{
	write(1, &c, 1);
}

void		ft_putstr(const char *s)
{
	int		i;

	i = 0;
	while (s != 0 && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void		ft_putnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

static void	print_alpha(unsigned long long int c, int reg)
{
	if (c == 10)
		ft_putchar((reg) ? 'A' : 'a');
	if (c == 11)
		ft_putchar((reg) ? 'B' : 'b');
	if (c == 12)
		ft_putchar((reg) ? 'C' : 'c');
	if (c == 13)
		ft_putchar((reg) ? 'D' : 'd');
	if (c == 14)
		ft_putchar((reg) ? 'E' : 'e');
	if (c == 15)
		ft_putchar((reg) ? 'F' : 'f');
}

void		ft_putnbr_hex(unsigned long long int n, int reg)
{
	if (n >= 16)
		ft_putnbr_hex((n / 16), reg);
	if ((n % 16) < 10)
		ft_putchar(n % 16 + '0');
	else
		print_alpha(n % 16, reg);
}
