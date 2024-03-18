/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:42:35 by lzerpa            #+#    #+#             */
/*   Updated: 2023/11/23 14:57:22 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst == NULL && src == NULL)
		return (dst);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (n-- > 0)
		*(temp_dst++) = *(temp_src++);
	return (dst);
}
