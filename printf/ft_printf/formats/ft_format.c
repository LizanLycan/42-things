/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:54:05 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/19 21:58:15 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_format(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	return (0);
}

int	ft_print_format(char conv, va_list *ap)
{
	if (conv == 'c')
		return (ft_print_char(ap));
	if (conv == 's')
		return (ft_print_str(ap));
	if (conv == 'p')
		return (ft_print_ptr(ap));
	if (conv == 'd')
		return (ft_print_dbl(ap));
	if (conv == 'i')
		return (ft_print_int(ap));
	if (conv == 'u')
		return (ft_print_uint(ap));
	if (conv == 'x')
		return (ft_print_hex_lower(ap));
	if (conv == 'X')
		return (ft_print_hex_upper(ap));
	return (0);
}
