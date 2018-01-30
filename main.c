/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:58:04 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/30 16:28:17 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		n[3];

	if (ac != 2)
		return (-1);
	if (ft_map_init(&map, av[1]) != 0)
		exit(1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, map.wsize.x, map.wsize.y, "FdF");
	map.mlx = mlx;
	map.win = win;
	ft_win_draw(&map);
	ft_putstr("--- Controls ---\n");
	ft_putstr("+ : zoom in\n");
	ft_putstr("- : zoom out\n");
	ft_putstr("arrow keys : move\n");
	mlx_key_hook(win, ft_keyhooked, &map);
	mlx_loop(mlx);
	return (0);
}
