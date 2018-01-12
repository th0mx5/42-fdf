/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:58:04 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/12 16:12:38 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>

typedef struct t_coord t_coord;
struct t_coord
{
	int x;
	int y;
};

int		ft_countfdlines(int fd)
{
	int lines;
	char *s;
	lines = 0;
	while ((get_next_line(fd, &s)) > 0)
		lines++;
	return (lines);
}

void	ft_drawline(void *mlx, void *win, t_coord a, t_coord b)
{
	int k;
	k = 0;
	while (k < 100)
	{
		mlx_pixel_put(mlx, win, a.x + (k * (b.x - a.x)) / 100, a.y + (k * (b.y - a.y)) / 100, 0x00FFFFFF);
		k++;
	}
}

int		main(int ac, char **av)
{
	void *mlx;
	void *win;
	char *s;
	char **array;
	int x;
	int y;
	int y2;
	int i;
	int j;
	int fd[3];
	int winsize_x;
	int winsize_y;
	t_coord a;
	t_coord b;
	y = 50;
	x = 10;
	i = 0;
	j = 0;
	y2 = 0;
	if (ac != 2)
		return (-1);
	if (((fd[0] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (((fd[1] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (((fd[2] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	winsize_y = ft_countfdlines(fd[2]) * 50;
	winsize_x = winsize_y;;
	mlx = mlx_init();
	win = mlx_new_window(mlx, winsize_x, winsize_y, "FdF");
	while ((*s = get_next_line(fd[0], &s)) > 0)
	{
		i = 0;
		array = ft_strsplit(s, ' ');
		while (array[i] != 0)
		{
			a.x = (winsize_x / 5) + x;
			a.y = (winsize_y / 2) + (y - (i * 5) - ft_atoi(array[i]) * 3);
			x = x + 10;
			i++;
			if (array[i] != 0)
			{
				b.x = (winsize_x / 5) + x;
				b.y = (winsize_y / 2) + (y - (i * 5) - ft_atoi(array[i]) * 3);
			}
			//mlx_pixel_put(mlx, win, a.x, a.y, 0x00FFFFFF);
			ft_drawline(mlx, win, a, b);
		}
		j++;
		y = y + 5;
		x = 10 + (j * 10);
	}
	mlx_loop(mlx);
	return (0);
}
