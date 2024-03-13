/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/03/13 15:50:23 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_printf_count(int *a)
{
	int	j;

	j = 0;
	while (*a++ != INT_MAX)
		j++;
	return (j);
}

static size_t	ft_printf_array_element(int **a, char *type, int fd)
{
	if (*type == 'n')
	{
		if (*(type + 1) == 'x')
			return (ft_printf_arth(*((*a))++, 16, 0, fd));
		else if (*(type + 1) == 'X' )
			return (ft_printf_arth(*((*a))++, 16, 1, fd));
		else if (*(type + 1) == 'o' )
			return (ft_printf_arth(*((*a))++, 8, 0, fd));
		else if (*(type + 1) == 'b' )
			return (ft_printf_arth(*((*a))++, 2, 0, fd));
		else
			return (ft_printf_arth(*((*a))++, 10, 0, fd));
	}
	return (0);
}

size_t	ft_printf_nbr_array(int *a, char *type, int fd)
{
	size_t			i;
	const size_t	j = ft_printf_count(a);
	size_t			c;

	if (!a)
		return (0);
	i = 0;
	c = 0;
	i += ft_printf_char(ARRAY_FORMATTER_S, fd);
	while (*a != INT_MAX)
	{
		i += ft_printf_array_element(&a, type, fd);
		if ((c++ + 1) != j)
			i += ft_printf_str(ARRAY_FORMATTER_M, fd);
	}
	i += ft_printf_char(ARRAY_FORMATTER_E, fd);
	return (i);
}
