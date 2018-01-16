/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:16:39 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/16 15:14:18 by thbernar         ###   ########.fr       */
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
	ft_map_counts(map, file_name);
	map->wsize.x = map->fsize.x * 40;
	map->wsize.y = map->fsize.y * 40;
	if (map->wsize.x < 50)
		map->wsize.x = 50;
	if (map->wsize.y < 50)
		map->wsize.y = 50;
	return (0);
}

int		ft_map_counts(t_map *map, char *file_name)
{
	char	*s;
	int		tmp;
	int		i;
	char	**array;
	int		fd[2];

	if (((fd[0] = open(file_name, O_RDONLY)) < 0))
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
