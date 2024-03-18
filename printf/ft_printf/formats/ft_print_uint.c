/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:03:20 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/22 13:48:17 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(va_list *ap)
{
	int	len;

	len = ft_putunbr_fd(va_arg(*ap, unsigned int), STDOUT_FILENO);
	va_end(*ap);
	return (len);
}
