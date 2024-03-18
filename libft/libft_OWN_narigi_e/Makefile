NAME	= libft.a

BONUS	= libft.a

FILES_NAME	= 	ft_isdigit \
				ft_isalpha \
				ft_strlen \
				ft_isalnum \
				ft_isascii \
				ft_isprint \
				ft_memset \
				ft_bzero \
				ft_memcpy \
				ft_memmove \
				ft_strlcpy \
				ft_strlcat \
				ft_toupper \
				ft_tolower \
				ft_strchr \
				ft_strrchr \
				ft_strncmp \
				ft_memchr \
				ft_memcmp \
				ft_strnstr \
				ft_atoi \
				ft_calloc \
				ft_strdup \
				ft_substr \
				ft_putchar_fd \
				ft_putstr_fd \
				ft_putnbr_fd \
				ft_putendl_fd \
				ft_strjoin \
				ft_strtrim \
				ft_split \
				ft_itoa \
				ft_strmapi \
				ft_striteri

BONUS_NAME	=	ft_lstnew \
				ft_lstadd_front \
				ft_lstsize \
				ft_lstlast \
				ft_lstadd_back \
				ft_lstdelone \
				ft_lstclear \
				ft_lstiter \
				ft_lstmap

COMPILER	= cc

COMPILER_FLAGS	= -Wall -Wextra -Werror

C_FILES	= $(FILES_NAME:%=%.c)

O_FILES	= $(FILES_NAME:%=%.o)

C_BONUS	= $(BONUS_NAME:%=%.c)

O_BONUS	= $(BONUS_NAME:%=%.o)

$(NAME):
	$(COMPILER) $(COMPILER_FLAGS) -c $(C_FILES)
	ar -rc $(NAME) $(O_FILES)

$(BONUS):
	$(COMPILER) $(COMPILER_FLAGS) -c $(C_FILES) $(C_BONUS)
	ar -rc $(NAME) $(O_FILES) $(O_BONUS)

all: $(NAME)

bonus: $(BONUS)

clean:
	rm -rf $(NAME)
	rm -rf $(O_FILES)
	rm -rf $(O_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus