/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:13:17 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/22 12:41:08 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dbl(va_list *ap)
{
	int	len;

	len = ft_putnbr_fd(va_arg(*ap, int), STDOUT_FILENO);
	va_end(*ap);
	return (len);
}
