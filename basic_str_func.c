/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:01:11 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/16 22:01:14 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char *str)
{
	int	value;

	value = 0;
	while (*str > 47 && *str < 58)
	{
		value = value * 10 + (int)(*str - 48);
		++str;
	}
	return (value);
}

int	ft_count(long long int d, int num_sys)
{
	int	j;

	j = 0;
	if (d == 0)
		return (1);
	while (d != 0)
	{
		d = d / num_sys;
		j++;
	}
	return (j);
}

int	ft_count_u(unsigned long long int d, int num_sys)
{
	int	j;

	j = 0;
	if (d == 0)
		return (1);
	while (d != 0)
	{
		d = d / num_sys;
		j++;
	}
	return (j);
}
