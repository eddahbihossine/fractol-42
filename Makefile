NAME = fract-ol
CC	= cc
FLAGS = -Wall -Wextra -Werror 

SOURCES = $(wildcard src/*.c)

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS)  -lmlx -framework OpenGL -framework  AppKit -ofast -o $(NAME)

%.o: %.c includes/fractol.h
	$(CC) $(FLAGS) -Imlx -c -ofast $< -o $@

bonus:all
clean:
	rm -rf src/*.o

fclean:clean
	rm -rf $(NAME)

re:fclean all









