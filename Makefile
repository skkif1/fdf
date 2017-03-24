CC = gcc -Wall -Wextra -Werror

FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fdf

FT_LS_SRC = main.c parse.c calculate_pos.c event_listener.c draw_map.c util.c

OBJECTS = $(subst .c,.o,$(FT_LS_SRC))

$(NAME): $(OBJECTS)
	@make -C libft/
	gcc $(OBJECTS) -o $(NAME) libft/libftprintf.a $(FLAGS)


all: $(NAME)

clean:
	@make -C libft/ clean
	rm -rf $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	rm -rf $(NAME) $(OBJECTS)

re: fclean all