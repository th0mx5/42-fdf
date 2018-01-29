/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:16:39 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/29 20:03:06 by thbernar         ###   ########.fr       */
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
	if (map->wsize.x > 1000)
		map->wsize.x = 1000;
	if (map->wsize.y > 1000)
		map->wsize.y = 1000;
	map->img = mlx_new_image(map->mlx, map->wsize.x, map->wsize.y);
	ft_map_allocvalues(map);
	ft_map_writevalues(map);
	ft_map_calc3dvalues(map);
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
	while ((get_next_line(fd[0], &s)) > 0)
	{
		i = 0;
		map->fsize.y++;
		tmp = 0;
		array = ft_strsplit(s, ' ');
		free(s);
		while (array[i])
		{
			if (ft_atoi(array[i]) > map->maxvalue)
				map->maxvalue = ft_atoi(array[i]);
			tmp++;
			i++;
		}
		ft_free_strsplit(array);
		if (tmp > map->fsize.x)
			map->fsize.x = tmp;
	}
	free(s);
	return (0);
}

int		ft_map_allocvalues(t_map *map)
{
	int i;
	int j;

	i = 0;
	map->values = (t_coord**)malloc(sizeof(t_coord*) * map->fsize.y);
	if (map->values == NULL)
		exit(-1);
	while (i < map->fsize.y)
	{
		map->values[i] = (t_coord*)malloc(sizeof(t_coord) * map->fsize.x);
		if (map->values[i] == NULL)
			exit(-1);
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
		free(s);
		while (j < map->fsize.x)
		{
			map->values[i][j].z = ft_atoi(array[j]);
			j++;
		}
		ft_free_strsplit(array);
		i++;
	}
	free(s);
	return (0);
}

int		ft_map_calc3dvalues(t_map *map)
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
			map->values[i][j].x = (map->wsize.x / 2) - (map->fsize.y * 10 * \
					map->zoom) + ((i + j) * 7) * map->zoom;
			map->values[i][j].x = map->values[i][j].x + map->xshift;
			map->values[i][j].y = (map->wsize.y / 2) + (((i - j) * 4 - \
						(map->values[i][j].z * 8)) * map->zoom);
			map->values[i][j].y = map->values[i][j].y + map->yshift;
			j++;
		}
		i++;
	}
	return (0);
}
