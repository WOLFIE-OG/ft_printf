/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/04/23 13:28:17 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printf_bool(bool b, int fd)
{
	if (b)
		return (ft_printf_str("true", fd));
	else
		return (ft_printf_str("false", fd));
}
