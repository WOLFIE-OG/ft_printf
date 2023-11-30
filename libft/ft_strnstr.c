/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:40:46 by otodd             #+#    #+#             */
/*   Updated: 2023/11/17 14:31:08 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			while (little[j] && big[i + j] == little[j] && i + j < len)
			{
				if (!little[j + 1])
					return ((char *)&big[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
