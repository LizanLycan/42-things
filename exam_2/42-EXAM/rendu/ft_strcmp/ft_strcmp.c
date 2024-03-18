#include <libc.h>

// #include <stdio.h>
// #include <unistd.h>

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

// int	main(void)
// {
// 	char *str1 = " ";
// 	char *str2 = "";

// 	printf("ST RESULT: %d %d\n", strcmp(str1, str2), ft_strcmp(str1, str2));
// }