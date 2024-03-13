/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_linked_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:00:53 by otodd             #+#    #+#             */
/*   Updated: 2024/03/13 15:51:06 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_printf_linked_list(t_list *n, char *type, int fd)
{
	size_t	i;

	i = 0;
	i += ft_printf_char(ARRAY_FORMATTER_S, fd);
	while (n)
	{
		if (*type == 'l')
			i += ft_printf_str((char *)n->content, fd);
		else if (*type == 'L' && *(type + 1) == 'x' )
			i += ft_printf_arth(*(int *)n->content, 16, 0, fd);
		else if (*type == 'L' && *(type + 1) == 'X' )
			i += ft_printf_arth(*(int *)n->content, 16, 1, fd);
		else if (*type == 'L' && *(type + 1) == 'o' )
			i += ft_printf_arth(*(int *)n->content, 8, 1, fd);
		else if (*type == 'L' && *(type + 1) == 'b' )
			i += ft_printf_arth(*(int *)n->content, 2, 0, fd);
		else if (*type == 'L')
			i += ft_printf_arth(*(int *)n->content, 10, 0, fd);
		if (n->next)
			i += ft_printf_str(ARRAY_FORMATTER_M, fd);
		n = n->next;
	}
	i += ft_printf_char(ARRAY_FORMATTER_E, fd);
	return (i);
}
