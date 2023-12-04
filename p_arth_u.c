/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_arth_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:33:53 by wolfie            #+#    #+#             */
/*   Updated: 2023/12/04 17:57:00 by otodd            ###   ########.fr       */
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

size_t	p_arth_u(unsigned int n, int base, int is_upper)
{
	int			len;
	char		*string;
	size_t		i;

	len = get_n_10_placements(p_get_abs(n), base);
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	while (len >= 0)
	{

		string[len--] = (convert_base(p_get_abs(n) % base, is_upper));
		n /= base;
	}
	i = p_str(string);
	free(string);
	return (i);
}

