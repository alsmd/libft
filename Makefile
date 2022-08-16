FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c  ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(FILES:.c=.o)

BONUS_FILES =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
				ft_lstiter.c ft_lstmap.c

BONUS_OBJS =  $(BONUS_FILES:.c=.o)

INCLUDES = .

NAME = libft.a

MAIN = main.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(MAIN:.c=.o)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN:.c=.o)  -L. -lft

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(FILES) ${BONUS_FILES}
	gcc -nostartfiles -shared -o libft.so $(OBJS) ${BONUS_OBJS}

.PHONY: run re fclean clean so