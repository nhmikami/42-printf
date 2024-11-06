/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:47:15 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/01 20:01:59 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_arg(va_list args, char spec);
int	print_chr(char c);
int	print_str(char *str);
int	print_nbr(long nbr);
int	print_unbr(unsigned int nbr);
int	print_ptr(va_list args);
int	print_hex(unsigned long n, const char *base);

#endif