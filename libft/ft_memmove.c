/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:14 by otodd             #+#    #+#             */
/*   Updated: 2023/11/17 14:27:47 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*proxy_d;
	unsigned const char	*proxy_s = src;
	unsigned char		*end_d;
	unsigned char		*end_s;

	if (!dest && !src)
		return (NULL);
	proxy_d = dest;
	if (proxy_d < proxy_s)
		ft_memcpy(dest, src, n);
	else
	{
		end_d = proxy_d + (n - 1);
		end_s = (unsigned char *)proxy_s + (n - 1);
		while (n--)
			*end_d-- = *end_s--;
	}
	return (dest);
}
