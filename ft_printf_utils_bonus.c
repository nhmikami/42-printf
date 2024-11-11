/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:52:36 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/11 16:36:11 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_larger(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

int	is_smaller(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}
