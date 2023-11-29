/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:35:51 by otodd             #+#    #+#             */
/*   Updated: 2023/11/17 12:13:10 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			index;
	size_t const	len = ft_strlen(s);

	if (!s)
		return ;
	index = 0;
	while (index < len)
	{
		(*f)(index, s + index);
		index++;
	}
}
