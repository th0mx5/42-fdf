/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:04:48 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/29 18:07:37 by thbernar         ###   ########.fr       */
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

void	ft_img_putpixel(t_map *map, int x, int y, int *color)
{
	int i;
	int j;

	j = 0;
	i = (x + (y * map->wsize.x)) * 4;
	if (x > 0 && y > 0 && x < map->wsize.x && y < map->wsize.y)
	{
		map->img_data[i] = color[0];
		map->img_data[i + 1] = color[1];
		map->img_data[i + 2] = color[2];
	}
}
