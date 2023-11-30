/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:09 by otodd             #+#    #+#             */
/*   Updated: 2023/11/17 16:06:03 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	total_string_length(const char *s, char c)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		if (*s != c)
		{
			result++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**string_list;
	size_t	index;
	size_t	len;

	if (!s)
		return (NULL);
	index = 0;
	string_list = malloc(sizeof(char *) * (total_string_length(s, c) + 1));
	if (!string_list)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			string_list[index++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	string_list[index] = 0;
	return (string_list);
}
