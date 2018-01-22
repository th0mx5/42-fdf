/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:58:04 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/22 20:39:29 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_map	map;

	if (ac != 2)
		return (-1);
	if (ft_map_init(&map, av[1]) != 0)
		exit(1);
	mlx = mlx_init();
	win = mlx_new_window(mlx, map.wsize.x, map.wsize.y, "FdF");
	map.mlx = mlx;
	map.win = win;
	int i = 0;
	int j = 0;
	while (i < map.fsize.y)
	{
		j = 0;
		while (j < map.fsize.x)
		{
			printf("(%d, %d) ", map.values3d[i][j].x, map.values3d[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
	//exit(0);
	ft_win_draw(map);
	mlx_key_hook(win, ft_keyhooked, &map);
	mlx_loop(mlx);
	free((void*)&map);
	return (0);
}
