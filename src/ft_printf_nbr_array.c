/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/02/05 20:52:19 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printf_nbr_array(int *a)
{
	size_t	i;
	size_t	j;
	size_t	c;
	int 	*k;

	if (!a)
		*a = 0;
	i = 0;
	j = 0;
	c = 0;
	k = a;
	while (*k++ != INT_MAX)
		j++;
	i += ft_printf_char('[');
	while (*a != INT_MAX)
	{
		i += ft_printf_arth(*a++, 10, 0);
		if (c + 1!= j)
			i += ft_printf_str(", ");
		c++;
	}
	i += ft_printf_char(']');
	return (i);
}
