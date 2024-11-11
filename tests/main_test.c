/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:21:38 by naharumi          #+#    #+#             */
/*   Updated: 2024/11/11 17:44:38 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main()
{

	// cc -Wall -Wextra -Werror ft_printf.c ft_printf_utils.c main_test.c
	printf("- no args\n");
	printf(" count = %i\n", ft_printf("no args: oi!"));
	printf(" count = %i\n", printf("no args: oi!"));
	
	printf("\n- char\n");
	printf(" count = %i\n", ft_printf("char: %c!", 'n'));
	printf(" count = %i\n", printf("char: %c!", 'n'));
	
	printf("\n- string\n");
	char	*s = 0;
	printf(" count = %i\n", ft_printf("string: %s!", "oi"));
	printf(" count = %i\n", printf("string: %s!", "oi"));
	printf(" count = %i\n", ft_printf("string: %s!", s));
	printf(" count = %i\n", printf("string: %s!", s));
	
	printf("\n- pointer\n");
	int x = 42;
	printf("count = %i\n", ft_printf("pointer: %p!\n", (void*)&x));
	printf("count = %i\n", printf("pointer: %p!\n", (void*)&x));
	printf("count = %i\n", ft_printf("pointer: %p!\n", (void*)0));
	printf("count = %i\n", printf("pointer: %p!\n", (void*)0));
	
	printf("\n- integer / double\n");
	printf("i, 0\n");
	printf(" count = %i\n", ft_printf("int: %i!", 0));
	printf(" count = %i\n", printf("int: %i!", 0));
	printf("i, 42\n");
	printf(" count = %i\n", ft_printf("int: %i!", 42));
	printf(" count = %i\n", printf("int: %i!", 42));
	printf("i, -42\n");
	printf(" count = %i\n", ft_printf("int: %i!", -42));
	printf(" count = %i\n", printf("int: %i!", -42));
	printf("d, INT_MAX\n");
	printf(" count = %i\n", ft_printf("int: %d!", INT_MAX));
	printf(" count = %i\n", printf("int: %d!", INT_MAX));
	printf("d, INT_MIN\n");
	printf(" count = %i\n", ft_printf("int: %d!", INT_MIN));
	printf(" count = %i\n", printf("int: %d!", INT_MIN));
	
	printf("\n- unsigned integer\n");
	printf("u, 0\n");
	printf(" count = %i\n", ft_printf("uint: %u!", 0));
	printf(" count = %i\n", printf("uint: %u!", 0));
	printf("u, UINT_MAX\n");
	printf(" count = %i\n", ft_printf("uint: %u!", UINT_MAX));
	printf(" count = %i\n", printf("uint: %u!", UINT_MAX));
	
	printf("\n- hexadecimal\n");
	printf("x, 0\n");
	printf(" count = %i\n", ft_printf("hexadecimal uppercase: %x!", 0));
	printf(" count = %i\n", printf("hexadecimal uppercase: %x!", 0));
	printf("x, 255\n");
	printf(" count = %i\n", ft_printf("hexadecimal lowercase: %x!", 255));
	printf(" count = %i\n", printf("hexadecimal lowercase: %x!", 255));
	printf("X, 255\n");
	printf(" count = %i\n", ft_printf("hexadecimal uppercase: %X!", 255));
	printf(" count = %i\n", printf("hexadecimal uppercase: %X!", 255));
	printf("X, -255\n");
	printf(" count = %i\n", ft_printf("hexadecimal uppercase: %X!", -255));
	printf(" count = %i\n", printf("hexadecimal uppercase: %X!", -255));
	
	printf("\n- percentage\n");
	printf(" count = %i\n", ft_printf("percentage case: %%!"));
	printf(" count = %i\n", printf("percentage case: %%!"));
}
