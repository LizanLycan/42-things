# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzerpa <lzerpa@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 21:40:41 by lzerpa            #+#    #+#              #
#    Updated: 2023/12/22 13:51:14 by lzerpa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

FILES_NAME	= 	ft_printf \
				formats/ft_print_uint \
				formats/ft_print_int \
				formats/ft_print_char \
				formats/ft_print_str \
				formats/ft_print_ptr \
				formats/ft_print_hex_lower \
				formats/ft_print_hex_upper \
				formats/ft_print_dbl \
				formats/ft_format \
				libft/ft_putchar_fd \
				libft/ft_putstr_fd \
				libft/ft_putnbr_fd \
				libft/ft_putunbr_fd \
				libft/ft_strlen \
				libft/ft_putnbr_hex_lower_fd \
				libft/ft_putnbr_hex_upper_fd \
				libft/ft_putulongnbr_hex_fd \

COMPILER	= cc

COMPILER_FLAGS	= -Wall -Wextra -Werror

INCLUDES = -I./

O_FILES	= $(FILES_NAME:%=%.o)

$(NAME): $(O_FILES)
	ar -rc $(NAME) $(O_FILES)
	ranlib $(NAME)

$(O_FILES): %.o: %.c
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
