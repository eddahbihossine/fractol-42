NAME = fract-ol

FLAGS = -Wall -Wextra -Werror

SOURCES =	color.c \
			main.c \
			mandelbrot.c \
			utils.c \
			init.c\
			bonus.c \
			julia.c \
			hooks.c \

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -fsanitize=address -lmlx -framework OpenGL -framework  AppKit -o fast -o $(NAME)

%.o: %.c fractal.h
	$(CC) $(FLAGS) -Imlx -c -ofast $< -o $@

bonus:all
clean:
	rm -rf *.o

fclean:clean
	rm -rf $(NAME)

re:fclean all








