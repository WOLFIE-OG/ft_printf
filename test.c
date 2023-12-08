/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:27 by otodd             #+#    #+#             */
/*   Updated: 2023/12/08 17:52:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include "ANSI-color-codes.h"

char	*EDGES = "\n================================================================\n";

int	main(void)
{
	int				val = INT_MIN;
	int				*ptr = &val;
	unsigned int	nbr_val = 1234567;

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is %c test for char."reset, 'a'));
	printf("\n	Original:		%d chars", printf(GRN"This is %c test for char."reset, 'a'));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is %c test for char and this is a test for %yyy"reset, 'a'));
	printf("\n	Original:		%d chars", printf(GRN"This is %c test for char and this is a test for %yyy"reset, 'a'));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for str %s."reset, NULL));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for str %s."reset, NULL));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is a test for digit / int and this is %d"reset, NULL));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for digit / int and this is %d"reset, NULL));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for lower hex and this is %x"reset, INT_MAX));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for lower hex and this is %x"reset, INT_MAX));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for upper hex and this is %X"reset, INT_MAX));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for upper hex and this is %X"reset, INT_MAX));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own: 			%d chars\n\n", ft_printf(GRN"This is a test for ptr and this is %p"reset, NULL));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for ptr and this is %p"reset, NULL));
	printf(BLU"%s"reset, EDGES);

	printf(BLU"%s"reset, EDGES);
	printf("\n	Own:			%d chars\n\n", ft_printf(GRN"This is a test for unsigned int and this is %u"reset, NULL));
	printf("\n	Original:		%d chars", printf(GRN"This is a test for unsigned int and this is %u"reset, NULL));
	printf(BLU"%s"reset, EDGES);
}
