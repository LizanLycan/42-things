/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:54:18 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/20 19:55:13 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list *ap)
{
	int	len;

	len = ft_putnbr_fd(va_arg(*ap, int), STDOUT_FILENO);
	va_end(*ap);
	return (len);
}
