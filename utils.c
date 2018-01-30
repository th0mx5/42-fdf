/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:04:48 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/30 15:07:02 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_strsplit(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_img_putpixel(t_map *map, t_coord p, int *color)
{
	int i;
	int j;

	j = 0;
	i = (p.x + (p.y * map->wsize.x)) * 4;
	if (p.x > 0 && p.y > 0 && p.x < map->wsize.x && p.y < map->wsize.y)
	{
		map->img_data[i] = color[0];
		map->img_data[i + 1] = color[1];
		map->img_data[i + 2] = color[2];
	}
}

t_coord	ft_transform(t_map *map, t_coord a)
{
	t_coord b;

	b.x = (map->wsize.x / 2) - (map->fsize.y * 10 * \
			map->zoom) + ((a.y + a.x) * 7) * map->zoom;
	b.x = b.x + map->xshift;
	b.y = (map->wsize.y / 2) + (((a.y - a.x) * 4 - (a.z * 8)) * map->zoom);
	b.y = b.y + map->yshift;
	b.z = a.z;
	return (b);
}
