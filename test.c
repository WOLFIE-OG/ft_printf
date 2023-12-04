/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/04 16:09:20 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("\n\nPrinted %d chars", ft_printf("This is %c test for char.\n", 'a'));
	printf("\n\nPrinted %d chars", ft_printf("This is a test for str %s.\n", "and this is the test string"));
	printf("\n\nPrinted %d chars", ft_printf("This is a test for digit / int and this is %d\n", INT_MAX));
	printf("\n\nPrinted %d chars", ft_printf("This is a test for hex and this is %x\n", INT_MAX));
}
