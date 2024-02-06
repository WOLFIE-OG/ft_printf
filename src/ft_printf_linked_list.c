/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_linked_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/02/06 17:32:04 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printf_linked_list(t_list *n, char *type)
{
	size_t	i;

	i = 0;
	i += ft_printf_char('[');
	while (n)
	{
		if (*type == 'l')
			i += ft_printf_str((char *)n->content);
		else if (*type == 'L' && *(type + 1) == 'a' )
			i += ft_printf_arth(*(int *)n->content, 16, 0);
		else if (*type == 'L' && *(type + 1) == 'A' )
			i += ft_printf_arth(*(int *)n->content, 16, 1);
		else if (*type == 'L' && *(type + 1) == 'o' )
			i += ft_printf_arth(*(int *)n->content, 8, 1);
		else if (*type == 'L' && *(type + 1) == 'b' )
			i += ft_printf_arth(*(int *)n->content, 2, 0);
		else if (*type == 'L')
			i += ft_printf_arth(*(int *)n->content, 10, 0);
		if (n->next)
			i += ft_printf_str(", ");
		n = n->next;
	}
	i += ft_printf_char(']');
	return (i);
}
