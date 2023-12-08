/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/08 18:14:50 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include "ANSI-color-codes.h"

char	*EDGES = "\n================================================================\n";

int	main(void)
{
	char			test_char = 'a';
	char			*test_str = "|I AM A TEST STRINGS|";
	int				test_int_val = INT_MIN;
	int				*test_int_ptr = &test_int_val;
	unsigned int	test_unsigned_int = 123456;

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is %c test for char."reset, test_char));
	printf("\n	Original:		%d chars", printf(GRN"This is %c test for char."reset, test_char));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is %c test for char and this is a test for %yyy"reset, test_char));
	printf("\n	Original:		%d chars", printf(GRN"This is %c test for char and this is a test for %yyy"reset, test_char));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for str %s."reset, test_str));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for str %s."reset, test_str));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is a test for digit and this is %d"reset, test_int_val));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for digit and this is %d"reset, test_int_val));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is a test for int and this is %i"reset, test_int_val));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for int and this is %i"reset, test_int_val));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for lower hex and this is %x"reset, test_unsigned_int));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for lower hex and this is %x"reset, test_unsigned_int));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for upper hex and this is %X"reset, test_unsigned_int));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for upper hex and this is %X"reset, test_unsigned_int));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is a test for ptr and this is %p"reset, test_int_ptr));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for ptr and this is %p"reset, test_int_ptr));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for unsigned int and this is %u"reset, test_unsigned_int));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for unsigned int and this is %u"reset, test_unsigned_int));
	printf(BLU"%s"reset, EDGES);
}
