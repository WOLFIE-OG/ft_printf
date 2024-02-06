/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_linked_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/02/06 01:57:46 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printf_linked_list(t_list *n)
{
	size_t	i;

	i = 0;
	i += ft_printf_char('[');
	while (n)
	{
		i += ft_printf_str((char *)n->content);
		if (n->next)
			i += ft_printf_str(", ");
		n = n->next;
	}
	i += ft_printf_char(']');
	return (i);
}
