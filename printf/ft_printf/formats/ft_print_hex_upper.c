/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:44:05 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/21 20:46:49 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_upper(va_list *ap)
{
	int	len;

	len = ft_putnbr_hex_upper_fd(va_arg(*ap, unsigned int), STDOUT_FILENO);
	va_end(*ap);
	return (len);
}
