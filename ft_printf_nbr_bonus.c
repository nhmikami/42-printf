/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:00:12 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/11 16:36:08 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	nbr_minus(long nbr, t_flags *flags)
{
	int	len;
	int	count;

	count = 0;
	len = ft_nbrlen(nbr);
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	else if (flags->plus && nbr >= 0)
		count += ft_putchar('+');
	else if (flags->space && nbr >= 0)
		count += ft_putchar(' ');
	if (flags->zero)
		count += ft_putnchar('0', flags->zero_width - len - count);
	else if (flags->dot)
		count += ft_putnchar('0', flags->dot_width - len);
	if (!(flags->dot && flags->dot_width == 0 && nbr == 0))
		count += ft_putnbr(nbr);
	while (count < flags->minus_width)
		count += ft_putchar(' ');
	return (count);
}

static int	get_nbr_minwidth(long nbr, t_flags *flags, int len)
{
	int	min_width;

	if (nbr < 0 || flags->plus || flags->space)
	{
		min_width = is_larger(flags->dot_width + 1, flags->zero_width);
		min_width = is_larger(min_width, len + 1);
	}
	else
	{
		min_width = is_larger(flags->dot_width, flags->zero_width);
		min_width = is_larger(min_width, len);
	}
	return (min_width);
}

static void	nbr_nominus_put(long nbr, t_flags *flags, int len, int *count)
{
	if (nbr < 0)
	{
		*count += ft_putchar('-');
		nbr = -nbr;
	}
	else if (flags->plus && nbr >= 0)
		*count += ft_putchar('+');
	else if (flags->space && nbr >= 0)
		*count += ft_putchar(' ');
	if (flags->dot && flags->zero && (flags->dot_width > flags->zero_width))
		*count += ft_putnchar('0', flags->dot_width - len);
	else if (flags->zero)
		*count += ft_putnchar('0', flags->zero_width - len - *count);
	else if (flags->dot)
		*count += ft_putnchar('0', flags->dot_width - len);
	if (!(flags->dot && flags->dot_width == 0 && nbr == 0))
		*count += ft_putnbr(nbr);
	return ;
}

static int	nbr_nominus(long nbr, t_flags *flags)
{
	int	len;
	int	count;
	int	min_width;
	int	total_width;

	count = 0;
	len = ft_nbrlen(nbr);
	if (flags->dot && flags->dot_width == 0 && nbr == 0)
		len = 0;
	min_width = get_nbr_minwidth(nbr, flags, len);
	total_width = is_larger(min_width, flags->width);
	while (count < (total_width - min_width))
		count += ft_putchar(' ');
	if (flags->dot && flags->zero && (flags->zero_width > flags->dot_width))
	{
		if (nbr < 0 || flags->plus || flags->space)
			count += ft_putnchar(' ',
					flags->zero_width - is_larger(flags->dot_width, len) - 1);
		else
			count += ft_putnchar(' ',
					flags->zero_width - is_larger(flags->dot_width, len));
	}
	nbr_nominus_put(nbr, flags, len, &count);
	return (count);
}

int	print_nbr(long nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->minus)
		count += nbr_minus(nbr, flags);
	else
		count += nbr_nominus(nbr, flags);
	return (count);
}
