/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:44:00 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/21 20:46:22 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(va_list *ap)
{
	int	len;

	len = ft_putnbr_hex_lower_fd(va_arg(*ap, unsigned int), STDOUT_FILENO);
	va_end(*ap);
	return (len);
}
