/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:26:38 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/08 16:44:26 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ptr_minus(unsigned long ptr, t_flags *flags, int len)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_putstr("(nil)", 5);
	else
	{
		count += ft_putstr("0x", 2);
		count += ft_puthex(ptr, "0123456789abcdef");
	}
	while (count < is_larger(flags->minus_width, len))
		count += ft_putchar(' ');
	return (count);
}

int	print_ptr(unsigned long ptr, t_flags *flags)
{
	int				count;
	int				len;

	count = 0;
	if (ptr == 0)
		len = 5;
	else
		len = ft_unbrlen(ptr, 16) + 2;
	if (flags->minus)
		count += ptr_minus(ptr, flags, len);
	else
	{
		while (count < is_larger(flags->width, len) - len)
			count += ft_putchar(' ');
		if (ptr == 0)
			count += ft_putstr("(nil)", 5);
		else
		{
			count += ft_putstr("0x", 2);
			count += ft_puthex(ptr, "0123456789abcdef");
		}
	}
	return (count);
}
