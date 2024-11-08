/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:16:43 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/08 17:29:53 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	unbr_minus(unsigned long nbr, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	len = ft_unbrlen(nbr, 10);
	if (flags->zero)
		count += ft_putnchar('0', flags->zero_width - len);
	else if (flags->dot)
		count += ft_putnchar('0', flags->dot_width - len);
	if (!(flags->dot && flags->dot_width == 0 && nbr == 0))
		count += ft_putnbr(nbr);
	while (count < flags->minus_width)
		count += ft_putchar(' ');
	return (count);
}

int	unbr_nominus(unsigned long nbr, t_flags *flags)
{
	int	len;
	int	count;
	int	min_width;
	int	total_width;

	count = 0;
	len = ft_unbrlen(nbr, 10);
	if (flags->dot && flags->dot_width == 0 && nbr == 0)
		len = 0;
	min_width = is_larger(flags->dot_width, flags->zero_width);
	min_width = is_larger(min_width, len);
	total_width = is_larger(min_width, flags->width);
	while (count < (total_width - min_width))
		count += ft_putchar(' ');
	if (flags->dot && flags->zero && (flags->zero_width > flags->dot_width))
		count += ft_putnchar(' ',
				flags->zero_width - is_larger(flags->dot_width, len));
	if (flags->dot)
		count += ft_putnchar('0', flags->dot_width - len);
	else if (flags->zero)
		count += ft_putnchar('0', flags->zero_width - len);
	if (!(flags->dot && flags->dot_width == 0 && nbr == 0))
		count += ft_putnbr(nbr);
	return (count);
}

int	print_unbr(unsigned long nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->minus)
		count += unbr_minus(nbr, flags);
	else
		count += unbr_nominus(nbr, flags);
	return (count);
}
