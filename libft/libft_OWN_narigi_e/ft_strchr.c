/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:13:06 by lzerpa            #+#    #+#             */
/*   Updated: 2023/11/23 16:23:34 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	con_c;

	con_c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == con_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == con_c)
		return ((char *)&s[i]);
	return (NULL);
}
