/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_arth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:33:53 by wolfie            #+#    #+#             */
/*   Updated: 2023/12/04 16:15:38 by otodd            ###   ########.fr       */
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

static char	convert_base(int i)
{
	if (i < 10)
		return (i + '0');
	else
		return (i - 10 + 'a');
}

size_t	p_arth(int n, int base)
{
	const int	is_negative = p_is_negative_num(n);
	int			len;
	char		*string;
	size_t		i;

	len = get_n_10_placements(p_get_abs(n), base) + is_negative;
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	if (is_negative)
		string[0] = '-';
	while (len >= is_negative)
	{

		string[len--] = (convert_base(p_get_abs(n) % base));
		n /= base;
	}
	i = p_str(string);
	free(string);
	return (i);
}

