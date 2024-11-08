/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:46:12 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/08 15:23:47 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnchar(char c, int n)
{
	int	count;

	count = 0;
	if (n > 0)
	{
		while (count < n)
		{
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}

int	ft_putstr(char *str, int n)
{
	int		count;

	count = 0;
	while (*str && count < n)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(unsigned long nbr)
{
	int		count;
	char	c;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		count += ft_putchar(c);
	}
	return (count);
}

int	ft_puthex(unsigned long n, const char *base)
{
	int			count;
	char		c;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, base);
		count += ft_puthex(n % 16, base);
	}
	else
	{
		c = base[n];
		count += ft_putchar(c);
	}
	return (count);
}
