/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:48:59 by lzerpa            #+#    #+#             */
/*   Updated: 2023/11/24 18:40:01 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * 1. I allocate memory for the array of strings.
 *      I use ft_calloc because I want to initialize
 *      the array with at least number of characters
 *      of the string s + 1.
 * 2. I use two variables i and j to iterate through
 *      the string s and the array of strings str.
 * 3. After a variable k to store the index of the
 *      first character of the current word.
 * 4. I use a while loop to skip all the delimiters
 *      at the beginning of the string s.
 * 5. I use a while loop to store the index of the
 *      first character of the current word in k.
 * 6. I use a while loop to skip all the characters of the current word.
 * 7. I use an if statement to check if the current word is not empty.
 * 8. I use ft_substr to copy the current word into the array of strings str.
 * 9. I use a while loop to skip all the delimiters at the end of the string s.
 * 10. I return the array of strings str.
 *
 *
 * char	**ft_split(const char *s, char c)
 * {
 *	char	**str;
 *	int		i;
 *	int		j;
 *	int		k;
 *
 *	i = 0;
 *	j = 0;
 *	str = ft_calloc((ft_strlen(s) + 1), sizeof(char *));
 *	if (!str)
 *		return (NULL);
 *	while (s[i] != '\0')
 *	{
 *		while (s[i] == c)
 *			i++;
 *		k = i;
 *		while (s[i] != c && s[i] != '\0')
 *			i++;
 *		if (i > k)
 *			str[j++] = ft_substr(s, k, i - k);
 *	}
 *	str[j] = NULL;
 *	return (str);
 * }
 *
 * But... this solution allocate a lot of memory.
 *
 * The next version of ft_split uses two helper functions:
 * ft_count_words and ft_word_alloc.
 * The first function counts the number of words in the string s
 * that are separated by the character c.
 * The second function allocates memory for a word in the string s
 * that ends with the character c or the null character.
 *
 *
 */

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static char	*ft_word_alloc(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = ft_substr(s, 0, i);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str_arr;

	if (!s)
		return (NULL);
	str_arr = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!str_arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			str_arr[j] = ft_word_alloc(&s[i], c);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	str_arr[j] = NULL;
	return (str_arr);
}
