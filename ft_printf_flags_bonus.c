/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:45:38 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/08 16:01:54 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->minus_width = 0;
	flags->dot = 0;
	flags->dot_width = 0;
	flags->zero = 0;
	flags->zero_width = 0;
	flags->specifier = 0;
	return ;
}

void	parse_width(const char *format, t_flags *flags, int *i)
{
	if (format[*i] == '-')
	{
		flags->minus = 1;
		flags->minus_width = ft_atoi(format, i);
	}
	else if (format[*i] == '.')
	{
		flags->dot = 1;
		flags->dot_width = ft_atoi(format, i);
	}
	else if (format[*i] == '0')
	{
		flags->zero = 1;
		flags->zero_width = ft_atoi(format, i);
	}
	else if (format[*i] >= '0' && format[*i] <= '9')
	{
		flags->width = ft_atoi(format, i);
	}
	return ;
}

void	parse_flags(const char *format, t_flags *flags, int *i)
{
	if (format[*i] == '#' || format[*i] == ' ' || format[*i] == '+')
	{
		if (format[*i] == '#')
			flags->sharp = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
	else
		parse_width(format, flags, i);
	return ;
}
