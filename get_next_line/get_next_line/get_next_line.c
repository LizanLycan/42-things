/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:48:59 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/12 19:32:17 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 *
 *
It starts by allocating memory for the buffer variable,
	which will be used to read data from the file.
	If the file descriptor is invalid,
	the buffer size is less than or equal to 0, or the read operation fails,
	it frees any memory allocated to left_c and buffer, sets them to NULL,
	and returns NULL.

It then calls the ft_fill_line function,
	which reads data from the file into the buffer,
	and appends it to left_c.
	If a newline character is encountered,
	it stops reading and returns left_c.
	If an error occurs during the read operation,
	it frees left_c and returns NULL.

After ft_fill_line returns, it frees the buffer and sets it to NULL.

If line (which now holds the value of left_c) is NULL, it returns NULL.

It then calls the ft_set_line function,
	which finds the first newline character in line,
	and returns a new string that starts from the character
	after the newline to the end of line.
	This new string is assigned to left_c,
	so it can be used in the next call to get_next_line.

Finally, it returns line, which should now contain a
	line of text from the file.
 *
 *
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

void	ft_fill_str(char *res, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
}

char	*ft_set_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_c);
}

char	*ft_fill_line(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = ft_fill_line(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c = ft_set_line(line);
	return (line);
}

/**
 *
 * main.c
 *
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <filename>", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}


Exec with:


gcc -Wall -Wextra -Werror
	-D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o exec

./exec file.txt



 *
 *
*/

/**
 *
 * file.txt
 *
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec a diam lectus.
Maecenas congue ligula ac quam viverra nec consectetur ante hendrerit.
Praesent et diam eget libero. Nam, ut porta lorem lacinia consectetur.
Donec ut libero. Lorem, consectetur adipiscing elit.
Aenean ut gravida lorem. Ut turpis felis. Adipiscing id dolor.
Pellentesque auctor nisi id magna consequat sagittis.
Ut convallis libero in urna ultrices accumsan. Donec sed odio eros.
Donec viverra mi quis at malesuada arcu rhoncus. Cum sociis montes,
nascetur ridiculus mus. In rutrum accumsan ultricies. Mauris  est.
Vivamus fermentum semper porta. Nunc diam velit, adipiscing sagittis vel odio.
Maecenas convallis ullamcorper ultricies. Curabitur ornare,

id fringilla sem nunc vel mi. Volutpat, tristique elit urna et turpis.
Quisque mi metus, tincidunt et orci. Fusce congue vestibulum.



Ut dolor diam, elementum eu, porttitor vel elit. Curabitur gravida ornare.
*/