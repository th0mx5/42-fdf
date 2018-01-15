/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:58:04 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/15 17:41:08 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keyhooked(int keycode, void *params)
{
	if (keycode == 53)
		exit(0);
	printf("key : %d\n", keycode);
	return (0);
}

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		fd[2];
	int		stats[4];
	t_map	map;

	if (ac != 2)
		return (-1);
	if (((fd[0] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (((fd[1] = open(av[1], O_RDONLY)) < 0))
		return (-1);
	if (ft_map_init(&map, av[1], stats) != 0)
		exit(1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, map.wsize.x, map.wsize.y, "FdF");
	map.mlx = mlx;
	map.win = win;
	ft_readanddraw(map, stats, fd);
	mlx_key_hook(win, ft_keyhooked, 0);
	mlx_loop(mlx);
	return (0);
}
