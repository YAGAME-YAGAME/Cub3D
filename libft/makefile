NAME = libft.a
SOURCES = \
	ft_strlen.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strnstr.c ft_split.c ft_strncmp.c ft_substr.c\

OBJECTS = $(SOURCES:.c=.o)

AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $^

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus