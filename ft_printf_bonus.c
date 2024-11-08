/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:55:30 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/08 15:51:51 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_arg(va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->specifier == 'c')
		count += print_chr(va_arg(args, int), flags);
	else if (flags->specifier == 's')
		count += print_str(va_arg(args, char *), flags);
	else if (flags->specifier == 'p')
		count += print_ptr(va_arg(args, unsigned long), flags);
	else if (flags->specifier == 'd' || flags->specifier == 'i')
		count += print_nbr(va_arg(args, int), flags);
	else if (flags->specifier == 'u')
		count += print_unbr(va_arg(args, unsigned int), flags);
	else if (flags->specifier == 'x')
		count += print_hex(va_arg(args, unsigned int),
				"0123456789abcdef", flags);
	else if (flags->specifier == 'X')
		count += print_hex(va_arg(args, unsigned int),
				"0123456789ABCDEF", flags);
	else if (flags->specifier == '%')
		count += ft_putchar('%');
	return (count);
}

void	process_s(const char *format, va_list args, t_flags *flags, int *count)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			init_flags(flags);
			while (format[i] && !ft_strchr(SPECIFIERS, format[i]))
				parse_flags(format, flags, &i);
			if (format[i] && ft_strchr(SPECIFIERS, format[i]))
			{
				flags->specifier = format[i];
				i++;
			}
			*count += print_arg(args, flags);
		}
		else
		{
			*count += ft_putchar(format[i]);
			i++;
		}
	}
	return ;
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	t_flags	*flags;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	flags = malloc(sizeof(t_flags));
	process_s(format, args, flags, &count);
	va_end(args);
	free(flags);
	return (count);
}
