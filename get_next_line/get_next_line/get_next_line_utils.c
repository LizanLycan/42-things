/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:49:38 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/12 19:24:56 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	b;
	void	*p;
	char	*s;

	if (count == 0 || size == 0)
	{
		return (malloc(0));
	}
	b = count * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	else
	{
		s = (char *)p;
		while (b--)
			*s++ = 0;
	}
	return (p);
}

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

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	if (!s1)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new_string;
	int		j;

	i = 0;
	new_string = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] != '\0')
	{
		new_string[j] = s2[i];
		i++;
		j++;
	}
	new_string[j] = '\0';
	return (new_string);
}
