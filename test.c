/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/11 16:28:02 by otodd            ###   ########.fr       */
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

	printf(BLU"%s"reset, EDGES);

	int	i_ft = INT_MIN;
	int	char_printed_ft = 0;
	int	char_printed_og = 0;
	while (i_ft != INT_MAX)
	{
		char_printed_ft += ft_printf(GRN"%d | %x (%X)\n"reset, i_ft, i_ft, i_ft);
		char_printed_og += printf(GRN"%d | %x (%X)\n"reset, i_ft, i_ft, i_ft++);
	}
	int	i_u = INT_MIN;
	while (i_u != INT_MAX)
		ft_printf(GRN"%u\n"reset, i_u++);

	printf("FT: %d\nOG: %d\n", char_printed_ft, char_printed_og);
	

	printf(BLU"%s"reset, EDGES);
}
