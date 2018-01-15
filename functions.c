/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:54:53 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/15 18:13:05 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_readanddraw(t_map map, int *fd)
{
	char *s[2];

	*s[1] = get_next_line(fd[1], &s[1]);
	while ((*s[0] = get_next_line(fd[0], &s[0])) > 0 && \
			(*s[1] = get_next_line(fd[1], &s[1])) > 0)
		ft_readpoints(map, s);
}

void	ft_readpoints(t_map map, char **s)
{
	int			i;
	char		**array[2];
	static int	j;
	t_coord		p[3];
	t_coord		z;

	i = 0;
	array[0] = ft_strsplit(s[0], ' ');
	array[1] = ft_strsplit(s[1], ' ');
	while (array[0][i] != 0)
	{
		z.x = i;
		z.y = j;
		ft_setpoints(map, p, z, array);
		ft_drawline(map, p[0], p[1]);
		ft_drawline(map, p[0], p[2]);
		i++;
	}
	j++;
}

void	ft_setpoints(t_map map, t_coord *p, t_coord z, char ***array)
{
	int i;
	int j;
	int stats[4];

	i = z.x;
	j = z.y;
	stats[0] = map.fsize.y;
	stats[1] = map.fsize.x;
	stats[2] = map.wsize.x;
	stats[3] = map.wsize.y;
	p[0].x = (stats[2] / 2) - stats[0] * 10 + (j + i) * 10;
	p[0].y = (stats[3] / 2) + (j - i) * 5 - ft_atoi(array[0][i]) * 10;
	p[2].x = p[0].x + 10;
	p[2].y = (stats[3] / 2) + (j - i + 1) * 5 - ft_atoi(array[1][i]) * 10;
	i++;
	if (array[0][i] != 0)
	{
		p[1].x = (stats[2] / 2) - stats[0] * 10 + (j + i) * 10;
		p[1].y = (stats[3] / 2) + (j * 5) - (i * 5) - ft_atoi(array[0][i]) * 10;
	}
	else
		p[1] = p[0];
	if (i - 1 <= 0)
		p[2] = p[0];
}

int		ft_map_init(t_map *map, char *file_name)
{
	char *s;
	int tmp;
	int i;
	char **array;
	int fd[2];
	map->fsize.y = 0;
	map->fsize.x = 0;
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
	map->wsize.x = map->fsize.x * 40;
	map->wsize.y = map->fsize.y * 40;
	if (map->wsize.x < 50)
		map->wsize.x = 50;
	if (map->wsize.y < 50)
		map->wsize.y = 50;
	return (0);
}

void	ft_drawline(t_map map, t_coord a, t_coord b)
{
	int k;

	k = 0;
	while (k < 100)
	{
		mlx_pixel_put(map.mlx, map.win, a.x + (k * (b.x - a.x)) / 100, a.y + \
				(k * (b.y - a.y)) / 100, 0x00FFFFFF);
		k++;
	}
}
