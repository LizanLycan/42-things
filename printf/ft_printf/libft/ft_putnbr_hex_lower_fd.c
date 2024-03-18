/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lower_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:26:25 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/22 13:37:33 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex_lower_fd(unsigned int n, int fd)
{
	char	digit;
	int		len;

	len = 0;
	if (n > 15)
	{
		len += ft_putnbr_hex_lower_fd(n / 16, fd);
		len += ft_putnbr_hex_lower_fd(n % 16, fd);
	}
	else
	{
		if (n < 10)
			digit = n + '0';
		else
			digit = n + 'a' - 10;
		ft_putchar_fd(digit, fd);
		len++;
	}
	return (len);
}
