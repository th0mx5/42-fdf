/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:54:53 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/31 23:28:29 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_win_draw(t_map *map)
{
	int			i;
	int			n[3];

	i = 0;
	map->img = mlx_new_image(map->win, map->wsize.x, map->wsize.y);
	map->img_data = (int*)mlx_get_data_addr(map->img, &n[0], &n[1], &n[2]);
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
	//ft_putstr("MAP PRINTED !\n");
}

void	ft_drawline(t_map map, t_coord a, t_coord b)
{
	int k;
	int max;
	t_coord p;
	int color;

	a = ft_transform(&map, a);
	b = ft_transform(&map, b);
	k = 0;
	max = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	color = 0xFFFFFF;
	while (k < max)
	{
		p.x = a.x + (k * (b.x - a.x)) / max;
		p.y = a.y + (k * (b.y - a.y)) / max;
		p.z = ((a.z + b.z) / 0.02) / map.maxvalue;
		if (p.z > 30)
			color = 0x00BD8D46;
		else if (p.z > 10)
			color = 0x008FCF3C;
		else
			color = 0x008CC6D7;
		ft_img_putpixel(&map, p, color);
		k++;
	}
}

void	ft_img_putpixel(t_map *map, t_coord p, int color)
{
	int i;
	int j;

	j = 0;
	i = (p.x + (p.y * map->wsize.x));
	if (p.x > 0 && p.y > 0 && p.x < map->wsize.x && p.y < map->wsize.y)
		map->img_data[i] = color;
}
