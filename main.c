/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:58:04 by thbernar          #+#    #+#             */
/*   Updated: 2018/02/01 01:07:17 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keyhooked(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		map->zoom = map->zoom + 0.1;
	if (keycode == 78 && map->zoom > 0.2)
		map->zoom = map->zoom - 0.1;
	if (keycode == 123)
		map->xshift = map->xshift + 10;
	if (keycode == 124)
		map->xshift = map->xshift - 10;
	if (keycode == 125)
		map->yshift = map->yshift - 10;
	if (keycode == 126)
		map->yshift = map->yshift + 10;
	if (keycode == 259)
		map->zshift = map->zshift + 1;
	if (keycode == 261)
		map->zshift = map->zshift - 1;
	ft_win_draw(map);
	return (0);
}

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_map	map;

	if (ac != 2 || ft_map_init(&map, av[1]) != 0)
		ft_error("usage : ./fdf [file_name]\n");
	mlx = mlx_init();
	win = mlx_new_window(mlx, map.wsize.x, map.wsize.y, "FdF");
	map.mlx = mlx;
	map.win = win;
	ft_win_draw(&map);
	ft_printcontrols();
	mlx_key_hook(win, ft_keyhooked, &map);
	mlx_loop(mlx);
	return (0);
}
