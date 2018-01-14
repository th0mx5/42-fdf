/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:58:04 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/14 19:25:31 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void *mlx;
	void *win;
	char *s;
	char *s1;
	char **array;
	char **array1;
	int x;
	int y;
	int i;
	int j;
	int fd[3];
	int winsize_x;
	int winsize_y;
	int file_stats[2];
	t_coord p[3];
	j = 0;
	if (ac != 2)
		return (-1);
	if (((fd[0] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (((fd[1] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (((fd[2] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	ft_checkfilestats(fd[2], file_stats);
	winsize_y = file_stats[0] * 40;
	winsize_x = file_stats[1] * 40;
	mlx = mlx_init();
	win = mlx_new_window(mlx, winsize_x, winsize_y, "FdF");
	*s1 = get_next_line(fd[1], &s1);
	while ((*s = get_next_line(fd[0], &s)) > 0 && (*s1 = get_next_line(fd[1], &s1)) > 0)
	{
		array = ft_strsplit(s, ' ');
		array1 = ft_strsplit(s1, ' ');
		x = j * 10;
		y = (winsize_y / 20) + j * 5;
		i = 0;
		while (array[i] != 0)
		{
			p[0].x = (winsize_x / 2) - file_stats[0]  * 10 + x;
			//printf("%d\n",p[0].x);
			p[0].y = (winsize_y / 2) + (y - (i * 5) - ft_atoi(array[i]) * 10);
			p[2].x = p[0].x + 10;
			p[2].y = (winsize_y / 2) + (y - (i * 5) - ft_atoi(array1[i]) * 10) + 5;
			x = x + 10;
			i++;
			if (array[i] != 0)
			{
				p[1].x = (winsize_x / 2) - file_stats[0] * 10 + x;
				p[1].y = (winsize_y / 2) + (y - (i * 5) - ft_atoi(array[i]) * 10);
				ft_drawline(mlx, win, p[0], p[1]);
			}
			if (i - 1 > 0)
				ft_drawline(mlx, win, p[0], p[2]);
		}
		j++;
		i = 0;
	}
	mlx_loop(mlx);
	return (0);
}
