/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:16:39 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/22 20:52:49 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_map_init(t_map *map, char *file_name)
{
	map->fname = ft_strdup(file_name);
	map->zoom = 1.00;
	map->fsize.y = 0;
	map->fsize.x = 0;
	map->maxvalue = 0;
	map->xshift = 0;
	map->yshift = 0;
	ft_map_counts(map);
	map->wsize.x = map->fsize.x * 40;
	map->wsize.y = map->fsize.y * 40;
	if (map->wsize.x < 50)
		map->wsize.x = 50;
	if (map->wsize.y < 50)
		map->wsize.y = 50;
	ft_map_allocvalues(map);
	ft_map_writevalues(map);
	ft_map_calc3Dvalues(map);
	return (0);
}

int		ft_map_counts(t_map *map)
{
	char	*s;
	int		tmp;
	int		i;
	char	**array;
	int		fd[2];

	if (((fd[0] = open(map->fname, O_RDONLY)) < 0))
		return (-1);
	while ((*s = get_next_line(fd[0], &s)) > 0)
	{
		i = 0;
		map->fsize.y++;
		tmp = 0;
		array = ft_strsplit(s, ' ');
		while (array[i])
		{
			if (ft_atoi(array[i]) > map->maxvalue)
				map->maxvalue = ft_atoi(array[i]);
			tmp++;
			i++;
		}
		if (tmp > map->fsize.x)
			map->fsize.x = tmp;
	}
	return (0);
}

int		ft_map_allocvalues(t_map *map)
{
	int i;
	int j;

	i = 0;
	map->values = (int**)malloc(sizeof(int*) * map->fsize.y);
	map->values3d = (t_coord**)malloc(sizeof(t_coord*) * map->fsize.y);
	while (i < map->fsize.y)
	{
		map->values[i] = (int*)malloc(sizeof(int) * map->fsize.x);
		map->values3d[i] = (t_coord*)malloc(sizeof(t_coord) * map->fsize.x);
		i++;
	}
	return (0);
}

int		ft_map_writevalues(t_map *map)
{
	int		j;
	int		i;
	int		fd;
	char	**array;
	char	*s;

	i = 0;
	j = 0;
	if (((fd = open(map->fname, O_RDONLY)) < 0))
		return (-1);
	while ((get_next_line(fd, &s)) > 0)
	{
		j = 0;
		array = ft_strsplit(s, ' ');
		while (j < map->fsize.x)
		{
			map->values[i][j] = ft_atoi(array[j]);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_map_calc3Dvalues(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->fsize.y)
	{
		j = 0;
		while (j < map->fsize.x)
		{
			map->values3d[i][j].x = (map->wsize.x / 2) - (map->fsize.y * 10 * map->zoom) + ((i + j) * 7) * map->zoom;
			map->values3d[i][j].x = map->values3d[i][j].x + map->xshift;
			map->values3d[i][j].y = (map->wsize.y / 2) + (((i - j) * 4 - (map->values[i][j] * 8)) * map->zoom);
			map->values3d[i][j].y = map->values3d[i][j].y + map->yshift;
			j++;
		}
		i++;
	}
	return (0);
}
