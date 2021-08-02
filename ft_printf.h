/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:39:36 by cdionna           #+#    #+#             */
/*   Updated: 2021/01/13 18:39:38 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			zero;
	int			minus;
	int			width;
	int			precision;
	char		type;
}				t_flags;

int				ft_printf(const char *format, ...);
int				print_str(const char *str, va_list ap);

int				parse_flags(t_flags *flags, const char *str, int i);
int				is_type(char letter);

int				parse_zero_minus(t_flags *flags, const char *str, int i);
int				parse_width(t_flags *flags, const char *str, int i);
int				parse_precision(t_flags *flags, const char *str, int i);
void			parse_star(t_flags *flags, va_list ap);

int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);

int				ft_atoi(char *str);
int				ft_count(long long int d, int num_sys);
int				ft_count_u(unsigned long long int d, int num_sys);

void			ft_putchar(int c);
void			ft_putstr(const char *s);
void			ft_putnbr(long long int n);
void			ft_putnbr_hex(unsigned long long int n, int reg);

int				print_type(t_flags *flags, va_list ap);
int				print_type_c(t_flags flags, char c);
int				print_type_s(t_flags flags, const char *str);
int				print_type_di(t_flags flags, int n);
int				print_type_u(t_flags flags, unsigned int n);
int				print_type_x(t_flags flags, unsigned int n, int reg);
int				print_type_p(t_flags flags, unsigned long long int p);

#endif
