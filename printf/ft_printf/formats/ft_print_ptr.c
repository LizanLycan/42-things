/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:38:54 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/22 12:41:32 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(va_list *ap)
{
	unsigned long int	ptr;
	int					len;

	len = 0;
	ptr = va_arg(*ap, unsigned long int);
	va_end(*ap);
	if (ptr)
	{
		ft_putstr_fd("0x", STDOUT_FILENO);
		len += 2;
		len += ft_putulongnbr_hex_fd(ptr, STDOUT_FILENO);
		return (len);
	}
	ft_putstr_fd("0x0", STDOUT_FILENO);
	return (3);
}
