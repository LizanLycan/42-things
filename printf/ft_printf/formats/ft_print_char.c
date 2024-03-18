/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:46:32 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/22 12:41:42 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *ap)
{
	ft_putchar_fd(va_arg(*ap, int), STDOUT_FILENO);
	va_end(*ap);
	return (1);
}
