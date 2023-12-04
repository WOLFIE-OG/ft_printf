/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/04 17:28:33 by otodd            ###   ########.fr       */
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
}
