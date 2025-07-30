NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = cub3D.c \
	   parssing/read_file.c			\
	   parssing/get_next_line.c		\
	   parssing/file_name.c			\
	   parssing/errors.c			\
	   parssing/leaks_mem.c			\
	   parssing/parssing_utils.c	\
	   parssing/texture_init.c		\
	   parssing/colors_init.c		\
	   parssing/parssing_map.c			\
	   parssing/check_wall.c		\

OBJS = $(SRCS:.c=.o)
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(OBJS) -o $(NAME)

%.o: %.c cub3D.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	@make -C libft

clean:
	@rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
.PHONY: all clean fclean re
