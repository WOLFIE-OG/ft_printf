/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/05/16 16:17:16 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_printf_ft_strarraylen(char **array)
{
	size_t	i;

	i = 0;
	while (*array++)
		i++;
	return (i);
}

size_t	ft_printf_str_array(char **a, char *type, int fd)
{
	size_t			i;
	const size_t	j = ft_printf_ft_strarraylen(a);
	size_t			c;

	if (!a)
		*a = "(null)";
	i = 0;
	c = 0;
	if (*type == 'a')
		i += ft_printf_str(ARRAY_FORMATTER_S, fd);
	while (*a)
	{
		i += ft_printf_str(*a++, fd);
		if ((c + 1) != j && *type == 'A')
			i += ft_printf_char(' ', fd);
		if ((c++ + 1) != j && *type == 'a')
			i += ft_printf_str(ARRAY_FORMATTER_M, fd);
	}
	if (*type == 'a')
		i += ft_printf_str(ARRAY_FORMATTER_E, fd);
	return (i);
}
