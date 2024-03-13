/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arth_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:33:53 by wolfie            #+#    #+#             */
/*   Updated: 2024/03/13 15:50:34 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_printf_placements(unsigned int n)
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

size_t	ft_printf_arth_u(unsigned int n, int fd)
{
	int			len;
	char		*string;
	size_t		i;

	len = ft_printf_placements(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len--] = '\0';
	while (len >= 0)
	{
		string[len--] = (n % 10) + '0';
		n /= 10;
	}
	i = ft_printf_str(string, fd);
	free(string);
	return (i);
}
