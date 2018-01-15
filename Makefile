all:
	cc -o fdf main.c functions.c functions_map.c libft/libft.a -lmlx -framework OpenGL -framework AppKit
