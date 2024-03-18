/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulongnbr_hex_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:48:58 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/21 20:41:40 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putulongnbr_hex_fd(unsigned long int n, int fd)
{
	char	digit;
	int		len;

	len = 0;
	if (n > 15)
	{
		len += ft_putulongnbr_hex_fd(n / 16, fd);
		len += ft_putulongnbr_hex_fd(n % 16, fd);
	}
	else
	{
		if (n < 10)
			digit = n + 48;
		else
			digit = n + 87;
		ft_putchar_fd(digit, fd);
		len++;
	}
	return (len);
}
