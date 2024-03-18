/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:53:36 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/21 21:27:14 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_print_format(char conv, va_list *ap);
int	ft_is_format(char c);

int	ft_print_char(va_list *ap);
int	ft_print_str(va_list *ap);
int	ft_print_ptr(va_list *ap);
int	ft_print_dbl(va_list *ap);
int	ft_print_int(va_list *ap);
int	ft_print_uint(va_list *ap);
int	ft_print_hex_lower(va_list *ap);
int	ft_print_hex_upper(va_list *ap);

#endif
