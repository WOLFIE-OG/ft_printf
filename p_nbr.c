/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nbr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:33:53 by wolfie            #+#    #+#             */
/*   Updated: 2023/12/03 00:17:14 by wolfie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_abs(int n)
{
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

static int	get_n_10_placements(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	is_negative_num(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int	p_nbr(int n)
{
	const int	is_negative = is_negative_num(n);
	int			len;
	char		*string;
	int			i;

	len = get_n_10_placements(get_abs(n)) + is_negative;
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	if (is_negative)
		string[0] = '-';
	while (len >= is_negative)
	{
		if (n == INT_MIN)
			string[len--] = '8';
		else
			string[len--] = (get_abs(n) % 10) + '0';
		n /= 10;
	}
	i = p_str(string);
	free(string);
	return (i);
}

