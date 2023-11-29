/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:03:18 by otodd             #+#    #+#             */
/*   Updated: 2023/11/17 12:13:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat_l(char *dest, char *src)
{
	char *const	cat_string = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (cat_string);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;

	new_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	return (ft_strcat_l(ft_strcpy_l(new_string, (char *)s1), (char *)s2));
}
