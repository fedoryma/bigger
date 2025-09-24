NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
SRCFILES = main.c \
		   create_map.c \
		   solve_map.c \
		   utils.c utils_str.c utils_is.c
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

OBJS = $(SRCS:.c=.o)

HEADER = bsq.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
