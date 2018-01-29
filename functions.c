/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:54:53 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/29 20:07:35 by thbernar         ###   ########.fr       */
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
	mlx_destroy_image(map->mlx, map->img);
	map->img = mlx_new_image(map->win, map->wsize.x, map->wsize.y);
	ft_map_calc3dvalues(map);
	ft_win_draw(map);
	return (0);
}

void	ft_win_draw(t_map *map)
{
	int			i;
	int			j;
	t_coord		p[3];
	int			n[5];

	map->img_data = mlx_get_data_addr(map->img, &n[0], &n[1], &n[2]);
	i = 0;
	while (i < map->fsize.y)
	{
		j = 0;
		while (j < map->fsize.x)
		{
			p[0] = map->values[i][j];
			p[1] = p[0];
			p[2] = p[0];
			if (j + 1 < map->fsize.x)
				p[1] = map->values[i][j + 1];
			if (i + 1 < map->fsize.y)
				p[2] = map->values[i + 1][j];
			ft_drawline(*map, p[0], p[1]);
			ft_drawline(*map, p[0], p[2]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}

void	ft_drawline(t_map map, t_coord a, t_coord b)
{
	int k;
	int max;
	int x;
	int y;
	int z;
	int color[3];

	k = 0;
	max = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	while (k < max)
	{
		x = a.x + (k * (b.x - a.x)) / max;
		y = a.y + (k * (b.y - a.y)) / max;
		z = ((a.z + b.z) / 0.02) / map.maxvalue;
		color[0] = 255;
		color[1] = 255;
		color[2] = 255;
		if (z > 30)
			color[0] = 50;
		else if (z > 15)
			color[0] = 150;
		else
			color[0] = 255;
		ft_img_putpixel(&map, x, y, color);
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
