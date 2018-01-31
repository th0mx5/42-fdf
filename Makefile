# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 00:25:16 by thbernar          #+#    #+#              #
#    Updated: 2018/02/01 00:31:23 by thbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

SRCS = functions.c \
	   functions_map.c \
	   utils.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	make -C minilibx
	mv libft/libft.a .
	mv minilibx/libmlx.a .
	gcc -Wall -g -Werror -Wextra -c $(SRCS)
	gcc -Wall -g -Werror -Wextra -L. -lmlx -lft -framework OpenGL -framework Appkit $(OBJS) -o $(NAME)

clean:
	make -C libft clean
	make -C minilibx clean
	rm -rf $(OBJS) libft.a libmlx.a

fclean: clean
	make -C libft fclean
	make -C minilibx clean
	rm -rf $(NAME)

re : fclean all
