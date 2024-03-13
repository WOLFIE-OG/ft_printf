/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/03/13 15:49:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printf_char_array(char **a, int fd)
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
	i += ft_printf_char(ARRAY_FORMATTER_S, fd);
	while (*a)
	{
		i += ft_printf_str(*a++, fd);
		if (c + 1 != j)
			i += ft_printf_str(ARRAY_FORMATTER_M, fd);
		c++;
	}
	i += ft_printf_char(ARRAY_FORMATTER_E, fd);
	return (i);
}
