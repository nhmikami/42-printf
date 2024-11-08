/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:00:57 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/08 17:56:14 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	hex_minus(unsigned long n, t_flags *flags, const char *base)
{
	int	len;
	int	count;

	count = 0;
	len = ft_unbrlen(n, 16);
	if (flags->sharp && n != 0)
	{
		if (!ft_strncmp(base, "0123456789abcdef", 16))
			count += ft_putstr("0x", 2);
		else
			count += ft_putstr("0X", 2);
	}
	if (flags->zero)
		count += ft_putnchar('0', flags->zero_width - len - count);
	else if (flags->dot)
		count += ft_putnchar('0', flags->dot_width - len);
	if (!(flags->dot && flags->dot_width == 0 && n == 0))
		count += ft_puthex(n, base);
	while (count < flags->minus_width)
		count += ft_putchar(' ');
	return (count);
}

int	get_minwidth(unsigned long n, t_flags *flags, int len)
{
	int	min_width;

	if (flags->dot)
	{
		if (flags->sharp && n != 0)
			min_width = is_larger(len, flags->dot_width) + 2;
		else
			min_width = is_larger(len, flags->dot_width);
	}
	else if (flags->zero)
	{
		if (flags->sharp && n != 0)
			min_width = is_larger(len + 2, flags->zero_width);
		else
			min_width = is_larger(len, flags->zero_width);
	}
	else
	{
		if (flags->sharp && n != 0)
			min_width = len + 2;
		else
			min_width = len;
	}
	return (min_width);
}

void	hex_sharp(const char *base, int *count)
{
	if (!ft_strncmp(base, "0123456789abcdef", 16))
		*count += ft_putstr("0x", 2);
	else
		*count += ft_putstr("0X", 2);
}

int	hex_nominus(unsigned long n, t_flags *flags, const char *base, int *count)
{
	int	len;
	int	min_width;
	int	total_width;

	len = ft_unbrlen(n, 16);
	if (flags->dot && flags->dot_width == 0 && n == 0)
		len = 0;
	min_width = get_minwidth(n, flags, len);
	total_width = is_larger(min_width, flags->width);
	while (*count < (total_width - min_width))
		*count += ft_putchar(' ');
	if (flags->sharp && n != 0)
		hex_sharp(base, count);
	if (flags->dot && flags->zero && (flags->zero_width > flags->dot_width))
	{
		if (flags->sharp)
			*count += ft_putnchar(' ',
					flags->zero_width - is_larger(flags->dot_width, len) - 2);
		else
			*count += ft_putnchar(' ',
					flags->zero_width - is_larger(flags->dot_width, len));
	}
	return (len);
}

int	print_hex(unsigned long n, const char *base, t_flags *flags)
{
	int	len;
	int	count;

	count = 0;
	if (flags->minus)
		count += hex_minus(n, flags, base);
	else
	{
		len = hex_nominus(n, flags, base, &count);
		if (flags->dot && flags->zero && (flags->dot_width > flags->zero_width))
			count += ft_putnchar('0', flags->dot_width - len);
		else if (flags->zero)
			count += ft_putnchar('0', flags->zero_width - len - count);
		else if (flags->dot)
			count += ft_putnchar('0', flags->dot_width - len);
		if (!(flags->dot && flags->dot_width == 0 && n == 0))
			count += ft_puthex(n, base);
	}
	return (count);
}
