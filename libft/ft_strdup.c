/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:37:59 by otodd             #+#    #+#             */
/*   Updated: 2023/11/17 12:13:07 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy_l(char *dest, const char *src)
{
	unsigned int		index;
	unsigned const int	len = ft_strlen((char *)src);

	index = 0;
	while (index < len)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*mem;

	mem = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mem)
		return (NULL);
	return (ft_strcpy_l(mem, s));
}
