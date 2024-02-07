/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/02/07 19:01:53 by otodd            ###   ########.fr       */
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

static size_t	ft_printf_array_element(int **a, char *type)
{
	if (*type == 'n')
	{
		if (*(type + 1) == 'a')
			return (ft_printf_arth(*((*a))++, 16, 0));
		else if (*(type + 1) == 'A' )
			return (ft_printf_arth(*((*a))++, 16, 1));
		else if (*(type + 1) == 'o' )
			return (ft_printf_arth(*((*a))++, 8, 0));
		else if (*(type + 1) == 'b' )
			return (ft_printf_arth(*((*a))++, 2, 0));
		else
			return (ft_printf_arth(*((*a))++, 10, 0));
	}
	return (0);
}

size_t	ft_printf_nbr_array(int *a, char *type)
{
	size_t			i;
	const size_t	j = ft_printf_count(a);
	size_t			c;

	if (!a)
		return (0);
	i = 0;
	c = 0;
	i += ft_printf_char('[');
	while (*a != INT_MAX)
	{
		i += ft_printf_array_element(&a, type);
		if ((c++ + 1) != j)
			i += ft_printf_str(", ");
	}
	i += ft_printf_char(']');
	return (i);
}
