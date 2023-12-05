/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/04 23:04:24 by wolfie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	val = 10;
	int	*ptr = &val;

	printf("\n================================\n");
	printf("\nPrinted %d chars", ft_printf("This is %c test for char.\n", 'a'));
	printf("\n================================\n");

	printf("\n================================\n");
	printf("\nPrinted %d chars", ft_printf("This is a test for str %s.\n", "and this is the test string"));
	printf("\n================================\n");

	printf("\n================================\n");
	printf("\nPrinted %d chars", ft_printf("This is a test for digit / int and this is %d\n", ptr));
	printf("\n================================\n");

	printf("\n================================\n");
	printf("\nPrinted %d chars", ft_printf("This is a test for lower hex and this is %x\n", ptr));
	printf("\n================================\n");

	printf("\n================================\n");
	printf("\nPrinted %d chars", ft_printf("This is a test for ptr and this is %p\n", ptr));
	printf("\n================================\n");

	printf("\n================================\n");
	printf("\nPrinted %d chars", ft_printf("This is a test for upper hex and this is %X\n", ptr));
	printf("\n================================\n");

	printf("\n================================\n");
	printf("\nPrinted %d chars", ft_printf("This is a test for unsigned int and this is %u\n", -100));
	printf("\n================================\n");
}
