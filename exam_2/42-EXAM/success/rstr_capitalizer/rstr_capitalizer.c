#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_not_space_and_so(char c)
{
	return (c != '\n' && c != '\t' && c != ' ');
}

int	is_upper_case(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_lower_case(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_a_letter(char c)
{
	return (is_upper_case(c) || is_lower_case(c));
}

int	main(int argc, char **argv)
{
	int i, j;
	int total_str;

	if (argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}

	total_str = argc - 1;
	i = 1;
	while (i <= total_str)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j + 1] == '\0' || !is_not_space_and_so(argv[i][j + 1]))
				&& is_a_letter(argv[i][j]))
			{
				if (is_lower_case(argv[i][j]))
					ft_putchar(argv[i][j] - 32);
				else
					ft_putchar(argv[i][j]);
			}
			else if (is_a_letter(argv[i][j]))
			{
				if (is_upper_case(argv[i][j]))
					ft_putchar(argv[i][j] + 32);
				else
					ft_putchar(argv[i][j]);
			}
			else
			{
				ft_putchar(argv[i][j]);
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}