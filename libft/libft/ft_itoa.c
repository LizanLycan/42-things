/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:24:23 by lzerpa            #+#    #+#             */
/*   Updated: 2023/11/24 18:55:29 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * Important part: I need to use long to avoid overflow on int type,
 * because the minimum value of int is -2147483648 and the maximum
 * value of int is 2147483647.
 *
 * It fills it with the digits of n in reverse order.
 * If n is negative, the function adds a minus
 * sign at the beginning of the string.
 *
 */

static size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	long_n;
	char	*str;

	long_n = n;
	len = ft_intlen(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (long_n < 0)
	{
		str[0] = '-';
		long_n = -long_n;
	}
	while (long_n > 9)
	{
		str[--len] = (long_n % 10) + '0';
		long_n /= 10;
	}
	str[--len] = long_n + '0';
	return (str);
}
