/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:13:26 by otodd             #+#    #+#             */
/*   Updated: 2023/12/13 13:16:46 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *in, ...);
size_t	p_char(char c);
size_t	p_str(char *s);
size_t	p_arth(unsigned int n, int base, int is_upper);
size_t	p_arth_u(unsigned int n);
size_t	p_ptr(uintptr_t n_ptr);
char	*p_strchr(char const *s, int c);
int		p_get_abs(int n, int base);
int		p_is_negative_num(int n, int base);

#endif