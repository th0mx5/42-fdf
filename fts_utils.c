/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:04:48 by thbernar          #+#    #+#             */
/*   Updated: 2018/02/01 01:05:10 by thbernar         ###   ########.fr       */
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

t_coord	ft_transform(t_map *map, t_coord a)
{
	t_coord b;
	int		k_z;

	//printf("%d %d %d\n", a.x, a.y, a.z);
	k_z = 6 + map->zshift;

	b.x = (map->wsize.x / 2) - (map->fsize.y * 10 * map->zoom);
	b.x = b.x + ((a.y + a.x) * 7) * map->zoom;
	b.x = b.x + map->xshift;

	b.y = (map->wsize.y / 2);
	b.y = b.y + (((a.y - a.x) * 4) - (a.z * k_z)) * map->zoom;
	b.y = b.y + map->yshift;

	b.z = a.z;
	return (b);
}

void	ft_printcontrols()
{
	ft_putstr("\n--- Controls ---\n");
	ft_putstr("+ : zoom in\n");
	ft_putstr("- : zoom out\n");
	ft_putstr("ARROWS : move\n");
	ft_putstr("LEFT OPTION : move\n");
	ft_putstr("LEFT CMD : move\n");
}

void	ft_error(char *s)
{
	ft_putstr(s);
	exit(-1);
}
