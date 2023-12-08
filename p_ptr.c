/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:33:53 by wolfie            #+#    #+#             */
/*   Updated: 2023/12/08 17:32:38 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_n_10_placements(uintptr_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	convert_base(uintptr_t i)
{
	char	c;

	c = 'a';
	if (i < 10)
		return (i + '0');
	else
		return (i - 10 + c);
}

static int	p_out(char *string)
{
	size_t	i;

	i = 0;
	i += p_str("0x");
	i += p_str(string);
	return (i);
}

size_t	p_ptr(uintptr_t n)
{
	int			len;
	char		*string;

	if (!n)
		return (p_str("(nil)"));
	len = get_n_10_placements(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	while (len >= 0)
	{
		string[len--] = (convert_base(n % 16));
		n /= 16;
	}
	return (p_out(string));
}
