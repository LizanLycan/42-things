/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:53:43 by lzerpa            #+#    #+#             */
/*   Updated: 2023/12/22 13:56:05 by lzerpa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(int *printed, int *i)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	*printed = *printed + 1;
	*i = *i + 1;
}

int	ft_read_argument(const char *str, int *i, va_list *ap)
{
	int	chars;

	if (str[*i + 1] && ft_is_format(str[*i + 1]))
	{
		chars = ft_print_format(str[*i + 1], ap);
		*i = *i + 1;
		return (chars);
	}
	else
	{
		ft_putchar_fd(str[*i], STDOUT_FILENO);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		printed;

	printed = 0;
	va_start(ap, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			printed++;
		}
		else
		{
			if (str[i + 1] && str[i + 1] == '%')
				ft_print_percent(&printed, &i);
			else
				printed += ft_read_argument(str, &i, &ap);
		}
	}
	return (printed);
}

/*
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int				i;
	char			c;
	char			*str;
	unsigned int	ui;
	void			*ptr;

	i = 42;
	c = 'a';
	str = "Hello, World!";
	ui = -1234567890;
	ptr = &i;
	int ret1, ret2;
	printf("Standard printf:\n");
	ret1 = printf("Printing integer: %d\n", i);
	ret1 += printf("Printing character: %c\n", c);
	ret1 += printf("Printing string: %s\n", str);
	ret1 += printf("Printing unsigned integer: %u\n", ui);
	ret1 += printf("Printing pointer: %p\n", ptr);
	ret1 += printf("Printing hexadecimal (lowercase): %x\n", i);
	ret1 += printf("Printing hexadecimal (uppercase): %X\n", i);
	printf("\nft_printf:\n");
	ret2 = ft_printf("Printing integer: %d\n", i);
	ret2 += ft_printf("Printing character: %c\n", c);
	ret2 += ft_printf("Printing string: %s\n", str);
	ret2 += ft_printf("Printing unsigned integer: %u\n", ui);
	ret2 += ft_printf("Printing pointer: %p\n", ptr);
	ret2 += ft_printf("Printing hexadecimal (lowercase): %x\n", i);
	ret2 += ft_printf("Printing hexadecimal (uppercase): %X\n", i);
	printf("\nReturn values:\n");
	printf("printf: %d\n", ret1);
	printf("ft_printf: %d\n", ret2);
	return (0);
}


RUN:
make

RUN:
gcc -Wall -Wextra -Werror -I. -L. -lftprintf main.c -o main





*/
