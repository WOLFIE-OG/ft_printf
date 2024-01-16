/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_arth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:33:53 by wolfie            #+#    #+#             */
/*   Updated: 2023/12/13 13:16:37 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_n_10_placements(unsigned int n, int base)
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

static char	convert_base(unsigned int i, int is_upper)
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

static int	p_out(char *string)
{
	size_t	i;

	i = 0;
	i += p_str(string);
	free(string);
	return (i);
}

size_t	p_arth(unsigned int n, int base, int is_upper)
{
	const int	is_negative = p_is_negative_num(n, base);
	int			len;
	char		*string;

	if ((int)n == INT_MIN && base == 10)
		return (p_str("-2147483648"));
	if ((int)n == INT_MAX && base == 10)
		return (p_str("2147483647"));
	n = p_get_abs(n, base);
	len = get_n_10_placements(n, base) + is_negative;
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	if (is_negative)
		string[0] = '-';
	while (len >= is_negative)
	{
		string[len--] = (convert_base(n % base, is_upper));
		n /= base;
	}
	return (p_out(string));
}
