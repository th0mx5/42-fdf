/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:54:53 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/22 20:40:46 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keyhooked(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		//free((void*)&map);
		exit(0);
	}
	if (keycode == 69)
		map->zoom = map->zoom + 0.1;
	if (keycode == 78)
		map->zoom = map->zoom - 0.1;
	if (keycode == 123)
		map->xshift = map->xshift + 10;
	if (keycode == 124)
		map->xshift = map->xshift - 10;
	if (keycode == 125)
		map->yshift = map->yshift - 10;
	if (keycode == 126)
		map->yshift = map->yshift + 10;
	ft_win_clear(*map);
	ft_map_calc3Dvalues(map);
	ft_win_draw(*map);
	//printf("keycode : %d\n", keycode);
	return (0);
}

void	ft_win_draw(t_map map)
{
	int		i;
	int			j;
	t_coord		p[3];

	i = 0;
	while (i < map.fsize.y)
	{
		j = 0;
		while (j < map.fsize.x)
		{
			p[0] = map.values3d[i][j];
			p[1] = p[0];
			p[2] = p[0];
			if (j + 1 < map.fsize.x)
				p[1] = map.values3d[i][j + 1];
			if (i + 1 < map.fsize.y)
				p[2] = map.values3d[i + 1][j];
			ft_drawline(map, p[0], p[1]);
			ft_drawline(map, p[0], p[2]);
			j++;
		}
		i++;
	}
}

void	ft_drawline(t_map map, t_coord a, t_coord b)
{
	int k;
	int max;
	int x;
	int y;

	k = 0;
	max = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	while (k < max)
	{
		x = a.x + (k * (b.x - a.x)) / max;
		y = a.y + (k * (b.y - a.y)) / max;
		mlx_pixel_put(map.mlx, map.win, x, y, 0x00FFFFFF);
		k++;
	}
}

void	ft_win_clear(t_map map)
{
	int j;
	int i;

	i = 0;
	while (i < map.wsize.y)
	{
		j = 0;
		while (j < map.wsize.x)
		{
			mlx_pixel_put(map.mlx, map.win, j, i, 0x000000);
			j++;
		}
		i++;
	}
}
