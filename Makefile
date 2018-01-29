all:
	cc -o fdf main.c functions.c functions_map.c utils.c libft/libft.a -lmlx -framework OpenGL -framework AppKit
