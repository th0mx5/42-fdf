/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:54:53 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/30 16:48:34 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keyhooked(int keycode, t_map *map)
{
	void *img2;
	if (keycode == 53)
		exit(0);
	img2 = mlx_new_image(map->win, map->wsize.x, map->wsize.y);
	mlx_put_image_to_window(map->mlx, map->win, img2, 0, 0);
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
	//ft_win_draw(map);
	return (0);
}

void	ft_win_draw(t_map *map)
{
	int			i;
	int			n[3];

	i = 0;
	map->img = mlx_new_image(map->win, map->wsize.x, map->wsize.y);
	map->img_data = mlx_get_data_addr(map->img, &n[0], &n[1], &n[2]);
	while (i - 1 < map->fsize.z)
	{
		if ((i + 1) % map->fsize.x != 0)
			ft_drawline(*map, map->values[i], map->values[i + 1]);
		if (i + map->fsize.x <= map->fsize.z)
			ft_drawline(*map, map->values[i], map->values[i + map->fsize.x]);
		i++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_destroy_image(map->mlx, map->img);
}

void	ft_drawline(t_map map, t_coord a, t_coord b)
{
	int k;
	int max;
	t_coord p;
	int color[3];

	a = ft_transform(&map, a);
	b = ft_transform(&map, b);
	k = 0;
	max = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	while (k < max)
	{
		p.x = a.x + (k * (b.x - a.x)) / max;
		p.y = a.y + (k * (b.y - a.y)) / max;
		p.z = ((a.z + b.z) / 0.02) / map.maxvalue;
		color[0] = 255;
		color[1] = 255;
		color[2] = 255;
		if (p.z > 30)
			color[0] = 50;
		else if (p.z > 15)
			color[0] = 150;
		else
			color[0] = 255;
		ft_img_putpixel(&map, p, color);
		k++;
	}
}
