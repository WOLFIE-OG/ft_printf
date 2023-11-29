/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:13:32 by otodd             #+#    #+#             */
/*   Updated: 2023/11/17 12:13:46 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	size_t const	len = ft_strlen(s);
	size_t			index;

	if (!s)
		return (ft_strdup(""));
	index = 0;
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (NULL);
	while (index < len)
	{
		new_string[index] = f(index, s[index]);
		index++;
	}
	new_string[index] = 0;
	return (new_string);
}
