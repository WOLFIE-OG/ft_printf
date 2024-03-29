/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:11:03 by wolfie            #+#    #+#             */
/*   Updated: 2024/03/28 12:47:03 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# define ARRAY_FORMATTER_S '['
# define ARRAY_FORMATTER_M ", "
# define ARRAY_FORMATTER_E ']'
# define ERR STDERR_FILENO
# define IN STDIN_FILENO
# define OUT STDOUT_FILENO
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
int		ft_fprintf(int fd, const char *in, ...);
size_t	ft_printf_char(char c, int fd);
size_t	ft_printf_str(char *s, int fd);
size_t	ft_printf_arth(unsigned int n, int base, int is_upper, int fd);
size_t	ft_printf_arth_l(long n, int base, int is_upper, int fd);
size_t	ft_printf_arth_u(unsigned int n, int fd);
size_t	ft_printf_ptr(uintptr_t n_ptr, int fd);
size_t	ft_printf_str_array(char **a, int fd);
size_t	ft_printf_nbr_array(int *a, char *type, int fd);
size_t	ft_printf_linked_list(t_list *n, char *type, int fd);
char	*ft_printf_strchr(char const *s, int c);
int		ft_printf_get_abs(int n, int base);
long	ft_printf_get_abs_l(long n, int base);
int		ft_printf_is_negative_num(int n, int base);
int		ft_printf_is_negative_num_l(long n, int base);
size_t	ft_printf_parse_type(const char *in, va_list arg, int fd);
size_t	ft_printf_parse_type_extra(const char *in, va_list arg, int fd);
void	ft_printf_extra_flags(const char **in);
void	ft_printf_process(const char **in, va_list args, size_t *count, int fd);

#endif