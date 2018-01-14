all:
	cc -o fdf main.c functions.c libft/libft.a -lmlx -framework OpenGL -framework AppKit
