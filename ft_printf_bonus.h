/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:47:15 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/08 15:53:45 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define SPECIFIERS "cspdiuxX%"

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int		width;
	int		sharp;
	int		space;
	int		plus;
	int		minus;
	int		minus_width;
	int		dot;
	int		dot_width;
	int		zero;
	int		zero_width;
	char	specifier;
}		t_flags;

int		ft_printf(const char *format, ...);

void	init_flags(t_flags *flags);
void	parse_flags(const char *format, t_flags *flags, int *i);
void	process_s(const char *format, va_list args, t_flags *flags, int *count);

int		print_arg(va_list args, t_flags *flags);
int		print_chr(char c, t_flags *flags);
int		print_str(char *str, t_flags *flags);
int		print_ptr(unsigned long ptr, t_flags *flags);
int		print_nbr(long nbr, t_flags *flags);
int		print_unbr(unsigned long nbr, t_flags *flags);
int		print_hex(unsigned long n, const char *base, t_flags *flags);

int		ft_putchar(char c);
int		ft_putnchar(char c, int n);
int		ft_putstr(char *str, int n);
int		ft_putnbr(unsigned long nbr);
int		ft_puthex(unsigned long n, const char *base);

int		ft_strlen(const char *s);
int		ft_nbrlen(long n);
int		ft_unbrlen(unsigned long n, int base);

int		ft_isdigit(int c);
int		is_larger(int n1, int n2);
int		is_smaller(int n1, int n2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr, int *i);
char	*ft_strchr(const char *s, int c);

#endif