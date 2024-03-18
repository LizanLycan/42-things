/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:03:02 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/13 17:55:21 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 *
 *
Same logic that in the main part, but we are considering the file descriptor
as a mapping way to the left_c array. For that reason we put in the .h file
the MAXIMUM_FD variable. In unix systems the maximum file descriptor we could
have is 10240, so we are going to use that number as the size of the array.
We found this number running in the console:

ulimit -n

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
	static char	*left_c[MAXIMUM_FD];
	char		*line;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0)
		{
			free(left_c[fd]);
			left_c[fd] = NULL;
		}
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = ft_fill_line(fd, left_c[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c[fd] = ft_set_line(line);
	return (line);
}

/**
 *
 * main.c
 *
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd_1;
	int		fd_2;
	char	*line;

	if (argc != 3)
	{
		printf("Usage: %s <filename> <other_filename>", argv[0]);
		return (1);
	}
	fd_1 = open(argv[1], O_RDONLY);
	fd_2 = open(argv[2], O_RDONLY);
	if (fd_1 == -1 || fd_2 == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd_1)) != NULL)
	{
		printf("LINE FD 1 -> %s", line);
		free(line);
	}
	close(fd_1);
	printf("\n");
	while ((line = get_next_line(fd_2)) != NULL)
	{
		printf("LINE FD 2 -> %s", line);
		free(line);
	}
	close(fd_2);
	return (0);
}


Exec with:


gcc -Wall -Wextra -Werror
	-D BUFFER_SIZE=32 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
		-o exec

./exec file.txt other_file.txt



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

/**
 *
 * other_file.txt
 *
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam nec purus
non ante blandit bibendum. Sed sit amet sem id dolor sollicitudin
elementum.

Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere
cubilia curae; Sed at massa non nulla placerat pharetra.

Aliquam erat volutpat. Donec id elit quis ipsum finibus consequat. Sed
quis feugiat elit, at mollis ligula. In at enim a velit maximus
efficitur.

Pellentesque habitant morbi tristique senectus et netus et malesuada
fames ac turpis egestas. Sed non neque id odio elementum
*/