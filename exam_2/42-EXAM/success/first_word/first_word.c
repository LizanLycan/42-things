#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_not_space_and_so(char c)
{
	return (c != '\n' && c != '\t' && c != ' ');
}

int	main(int argc, char **argv)
{
	int i;

	if (argc > 2 || argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}

	i = 0;

	while (!is_not_space_and_so(argv[1][i]))
		i++;
	while (argv[1][i] != '\0' && is_not_space_and_so(argv[1][i]))
	{
		ft_putchar(argv[1][i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}