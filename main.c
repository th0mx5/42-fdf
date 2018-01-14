/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:58:04 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/14 20:23:30 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int		main(int ac, char **av)
{
	void *mlx;
	void *win;
	int fd[3];
	int file_stats[2];

	t_coord wsize;
	if (ac != 2)
		return (-1);
	if (((fd[0] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (((fd[1] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (((fd[2] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	ft_checkfilestats(fd[2], file_stats);
	wsize.y = file_stats[0] * 40;
	wsize.x = file_stats[1] * 40;
	mlx = mlx_init();
	win = mlx_new_window(mlx, wsize.x, wsize.y, "FdF");
	ft_draw(mlx, win, fd, wsize, file_stats);
	mlx_loop(mlx);
	return (0);
}
