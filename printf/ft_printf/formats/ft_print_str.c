/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:58:45 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/19 22:18:59 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list *ap)
{
	char	*str;
	int		len;

	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT_FILENO);
	va_end(*ap);
	return (len);
}
