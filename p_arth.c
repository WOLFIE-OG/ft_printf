/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_arth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:33:53 by wolfie            #+#    #+#             */
/*   Updated: 2023/12/05 16:28:34 by wolfie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_n_10_placements(int n, int base)
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

static char	convert_base(int i, int is_upper)
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

static int	p_out(char *string, int is_pointer)
{
	size_t	i;

	i = 0;
	if (is_pointer)
		i += p_str("0x");
	i += p_str(string);
	free(string);
	return (i);
}

size_t	p_arth(int n, int base, int is_upper, int is_pointer)
{
	const int	is_negative = p_is_negative_num(n, base);
	int			len;
	char		*string;

	len = get_n_10_placements(p_get_abs(n), base) + is_negative;
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	if (is_negative)
		string[0] = '-';
	while (len >= is_negative)
	{
		string[len--] = (convert_base(p_get_abs(n) % base, is_upper));
		n /= base;
	}
	return (p_out(string, is_pointer));
}
