/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:44:24 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/22 13:44:52 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int				len;
	unsigned int	nbr;

	len = 1;
	nbr = n;
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return (len);
}
