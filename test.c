/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/05 17:09:04 by wolfie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

char	*EDGES = "\n================================================================\n";

int	main(void)
{
	uintptr_t		val = 10;
	uintptr_t		*ptr = &val;
	unsigned int	nbr_val = 1234567;

	printf("%s", EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf("This is %c test for char.", 'a'));
	printf("\n	Original:		%d chars", printf("This is %c test for char.", 'a'));
	printf("%s", EDGES);

	printf("%s", EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf("This is %c test for char and this is a test for %yyy", 'a'));
	printf("\n	Original:		%d chars", printf("This is %c test for char and this is a test for %yyy", 'a'));
	printf("%s", EDGES);

	printf("%s", EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf("This is a test for str %s.", "and this is the test string"));
	printf("\n	Original:		%d chars", printf("This is a test for str %s.", "and this is the test string"));
	printf("%s", EDGES);

	printf("%s", EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf("This is a test for digit / int and this is %d", ptr));
	printf("\n	Original:		%d chars", printf("This is a test for digit / int and this is %d", ptr));
	printf("%s", EDGES);

	printf("%s", EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf("This is a test for lower hex and this is %x", ptr));
	printf("\n	Original:		%d chars", printf("This is a test for lower hex and this is %x", ptr));
	printf("%s", EDGES);

	printf("%s", EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf("This is a test for upper hex and this is %X", ptr));
	printf("\n	Original:		%d chars", printf("This is a test for upper hex and this is %X", ptr));
	printf("%s", EDGES);

	printf("%s", EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf("This is a test for ptr and this is %p", ptr));
	printf("\n	Original:		%d chars", printf("This is a test for ptr and this is %p", ptr));
	printf("%s", EDGES);

	printf("%s", EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf("This is a test for unsigned int and this is %u", ptr));
	printf("\n	Original:		%d chars", printf("This is a test for unsigned int and this is %u", ptr));
	printf("%s", EDGES);
}
