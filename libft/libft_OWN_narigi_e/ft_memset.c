/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:50:27 by lzerpa            #+#    #+#             */
/*   Updated: 2023/11/23 14:11:08 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_ptr;

	temp_ptr = (unsigned char *)b;
	while (len-- > 0)
		*(temp_ptr++) = (unsigned char)c;
	return (b);
}
