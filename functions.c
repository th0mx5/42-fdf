/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:54:53 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/14 20:25:43 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(void *mlx, void *win, int *fd, t_coord wsize, int *file_stats)
{
	char **array;
	char **array1;
	char *s[2];
	int x;
	int y;
	int i;
	int j;
	t_coord p[3];

	j = 0;
	*s[1] = get_next_line(fd[1], &s[1]);
	while ((*s[0] = get_next_line(fd[0], &s[0])) > 0 && (*s[1] = get_next_line(fd[1], &s[1])) > 0)
	{
		i = 0;
		array = ft_strsplit(s[0], ' ');
		array1 = ft_strsplit(s[1], ' ');
		x = j * 10;
		y = (wsize.y / 20) + j * 5;
		while (array[i] != 0)
		{
			p[0].x = (wsize.x / 2) - file_stats[0]  * 10 + x;
			p[0].y = (wsize.y / 2) + (y - (i * 5) - ft_atoi(array[i]) * 10);
			p[2].x = p[0].x + 10;
			p[2].y = (wsize.y / 2) + (y - (i * 5) - ft_atoi(array1[i]) * 10) + 5;
			x = x + 10;
			i++;
			if (array[i] != 0)
			{
				p[1].x = (wsize.x / 2) - file_stats[0] * 10 + x;
				p[1].y = (wsize.y / 2) + (y - (i * 5) - ft_atoi(array[i]) * 10);
				ft_drawline(mlx, win, p[0], p[1]);
			}
			if (i - 1 > 0)
				ft_drawline(mlx, win, p[0], p[2]);
			printf("%d ", p[0].y);
		}
		printf("%s\n", s[0]);
		j++;
	}
}

void	ft_checkfilestats(int fd, int *stats)
{
	char *s;
	int tmp;
	int i;
	char **array;
	stats[0] = 0;
	stats[1] = 0;
	while ((*s = get_next_line(fd, &s)) > 0)
	{
		i = 0;
		stats[0]++;
		tmp = 0;
		array = ft_strsplit(s, ' ');
		while (array[i++])
			tmp++;
		if (tmp > stats[1])
			stats[1] = tmp;
	}
}

void	ft_drawline(void *mlx, void *win, t_coord a, t_coord b)
{
	int k;
	k = 0;
	while (k < 100)
	{
		mlx_pixel_put(mlx, win, a.x + (k * (b.x - a.x)) / 100, a.y + (k * (b.y - a.y)) / 100, 0x00FFFFFF);
		k++;
	}
}
