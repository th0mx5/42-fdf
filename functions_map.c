/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:16:39 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/15 18:21:53 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_map_init(t_map *map, char *file_name)
{
	map->fsize.y = 0;
	map->fsize.x = 0;
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
		while (array[i++])
			tmp++;
		if (tmp > map->fsize.x)
			map->fsize.x = tmp;
	}
	return (0);
}
