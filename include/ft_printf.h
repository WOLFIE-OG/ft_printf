/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:11:03 by wolfie            #+#    #+#             */
/*   Updated: 2024/02/06 12:35:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# if __has_include("../../../../include/list.h")
#  include "../../../../include/list.h"
# else

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# endif

int		ft_printf(const char *in, ...);
size_t	ft_printf_char(char c);
size_t	ft_printf_str(char *s);
size_t	ft_printf_arth(unsigned int n, int base, int is_upper);
size_t	ft_printf_arth_u(unsigned int n);
size_t	ft_printf_ptr(uintptr_t n_ptr);
size_t	ft_printf_char_array(char **a);
size_t	ft_printf_nbr_array(int *a);
size_t	ft_printf_linked_list(t_list *n, char type);
char	*ft_printf_strchr(char const *s, int c);
int		ft_printf_get_abs(int n, int base);
int		ft_printf_is_negative_num(int n, int base);

#endif