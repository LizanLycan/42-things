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
	while ((line = get_next_line(fd_2)) != NULL)
	{
		printf("LINE FD 2 -> %s", line);
		free(line);
	}
	close(fd_2);
	return (0);
}
