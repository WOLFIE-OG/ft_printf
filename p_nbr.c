/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nbr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:09:21 by otodd             #+#    #+#             */
/*   Updated: 2023/12/01 17:10:42 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_nbr(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			p_char('-', fd);
			ft_putnbr_fd((n / -10), fd);
			ft_putchar_fd('8', fd);
		}
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
	}
	else if (n < 10)
		ft_putchar_fd((n + '0'), fd);
	else
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	return (i);
}
