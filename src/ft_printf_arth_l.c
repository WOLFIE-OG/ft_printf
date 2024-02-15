/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arth_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:29:06 by otodd             #+#    #+#             */
/*   Updated: 2024/02/15 14:30:43 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_printf_placements(long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

static char	ft_printf_convert_base(long i, int is_upper)
{
	char	c;

	c = 'a';
	if (is_upper)
		c = 'A';
	if (i < 10)
		return (i + '0');
	else
		return (i - 10 + c);
}

static int	ft_printf_out(char *string)
{
	size_t	i;

	i = 0;
	i += ft_printf_str(string);
	free(string);
	return (i);
}

size_t	ft_printf_arth_l(long n, int base, int is_upper)
{
	const int	is_negative = ft_printf_is_negative_num_l(n, base);
	int			len;
	char		*string;

	if (n == LONG_MIN && base == 10)
		return (ft_printf_str("-2147483648"));
	if (n == LONG_MAX && base == 10)
		return (ft_printf_str("2147483647"));
	n = ft_printf_get_abs_l(n, base);
	len = ft_printf_placements(n, base) + is_negative;
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	if (is_negative)
		string[0] = '-';
	while (len >= is_negative)
	{
		string[len--] = (ft_printf_convert_base(n % base, is_upper));
		n /= base;
	}
	return (ft_printf_out(string));
}
