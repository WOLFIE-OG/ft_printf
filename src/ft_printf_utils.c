/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:26:54 by wolfie            #+#    #+#             */
/*   Updated: 2024/01/18 16:50:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_get_abs(int n, int base)
{
	if (base > 10)
		return (n);
	if (n == INT_MIN)
		return (INT_MAX);
	if (n < 0)
	{
		if (n == INT_MIN)
			return (INT_MAX);
		return (-n);
	}
	return (n);
}

int	ft_printf_is_negative_num(int n, int base)
{
	if (base == 10)
		if (n < 0)
			return (1);
	return (0);
}

char	*ft_printf_strchr(char const *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
