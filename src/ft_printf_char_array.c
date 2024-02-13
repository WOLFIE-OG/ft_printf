/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/02/07 19:40:43 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printf_char_array(char **a)
{
	size_t	i;
	size_t	j;
	size_t	c;
	char	**k;

	if (!a)
		*a = "(null)";
	i = 0;
	j = 0;
	c = 0;
	k = a;
	while (*k++)
		j++;
	i += ft_printf_char(ARRAY_FORMATTER_S);
	while (*a)
	{
		i += ft_printf_str(*a++);
		if (c + 1 != j)
			i += ft_printf_str(ARRAY_FORMATTER_M);
		c++;
	}
	i += ft_printf_char(ARRAY_FORMATTER_E);
	return (i);
}
