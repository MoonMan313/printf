/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:41:08 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/15 23:41:10 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if ((c > 47) && (c < 58))
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;

	if (s == 0)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!(dup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dup = ft_memcpy(dup, &s[start], len);
	dup[len] = '\0';
	return (dup);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;

	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	if (!n || p_src == p_dst)
		return (dst);
	while (n--)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
	}
	return (dst);
}
