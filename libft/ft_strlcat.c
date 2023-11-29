/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:20:33 by otodd             #+#    #+#             */
/*   Updated: 2023/11/17 12:13:17 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	index;
	size_t	result;

	d_len = ft_strlen(dst);
	s_len = ft_strlen((char *)src);
	index = 0;
	result = 0;
	if (size <= d_len)
		result = s_len + size;
	else
	{
		result = s_len + d_len;
		while (src[index] && d_len < size - 1)
			dst[d_len++] = src[index++];
	}
	dst[d_len] = '\0';
	return (result);
}
