/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:58:04 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/15 15:13:04 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		fd[3];
	int		stats[4];
	t_coord	wsize;

	if (ac != 2)
		return (-1);
	if (((fd[0] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (((fd[1] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (((fd[2] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	ft_checkfilestats(fd[2], stats);
	mlx = mlx_init();
	win = mlx_new_window(mlx, stats[2], stats[3], "FdF");
	ft_readanddraw(mlx, win, stats, fd);
	mlx_loop(mlx);
	return (0);
}
