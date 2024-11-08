/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:59:23 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/08 16:09:26 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_chr(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->minus != 0)
	{
		count += ft_putchar(c);
		while (count < flags->minus_width)
			count += ft_putchar(' ');
	}
	else
	{
		while (count < (flags->width - 1))
			count += ft_putchar(' ');
		count += ft_putchar(c);
	}
	return (count);
}

int	str_minus(char *str, t_flags *flags, int len)
{
	int	count;

	count = 0;
	if (!str && flags->dot && flags->dot_width < 6)
		count += ft_putstr("", 0);
	else if (!str)
		count += ft_putstr("(null)", 6);
	else
		count += ft_putstr(str, len);
	while (count < is_larger(flags->minus_width, len))
		count += ft_putchar(' ');
	return (count);
}

int	get_strlen(char *str, t_flags *flags)
{
	int	len;

	len = 0;
	if (!str && flags->dot && flags->dot_width < 6)
		len = 0;
	else if (!str)
		len = 6;
	else if (flags->dot)
		len = is_smaller(ft_strlen(str), flags->dot_width);
	else
		len = ft_strlen(str);
	return (len);
}

int	print_str(char *str, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	len = get_strlen(str, flags);
	if (flags->minus)
		count += str_minus(str, flags, len);
	else
	{
		while (count < is_larger(flags->width, len) - len)
			count += ft_putchar(' ');
		if (!str && flags->dot && flags->dot_width < 6)
			count += ft_putstr("", 0);
		else if (!str)
			count += ft_putstr("(null)", 6);
		else
			count += ft_putstr(str, len);
	}
	return (count);
}
