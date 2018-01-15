/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:54:53 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/15 15:51:34 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_readanddraw(void *mlx, void *win, int *stats, int *fd)
{
	char *s[2];

	*s[1] = get_next_line(fd[1], &s[1]);
	while ((*s[0] = get_next_line(fd[0], &s[0])) > 0 && \
			(*s[1] = get_next_line(fd[1], &s[1])) > 0)
		ft_readpoints(mlx, win, stats, s);
}

void	ft_readpoints(void *mlx, void *win, int *stats, char **s)
{
	int			i;
	char		**array[2];
	static int	j;
	t_coord		p[3];

	i = 0;
	array[0] = ft_strsplit(s[0], ' ');
	array[1] = ft_strsplit(s[1], ' ');
	while (array[0][i] != 0)
	{
		ft_setpoints(p, stats, i, j, array);
		ft_drawline(mlx, win, p[0], p[1]);
		ft_drawline(mlx, win, p[0], p[2]);
		i++;
	}
	j++;
}

void	ft_setpoints(t_coord *p, int *stats, int i, int j, char ***array)
{
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
	stats[2] = stats[1] * 40;
	stats[3] = stats[0] * 40;
}

void	ft_drawline(void *mlx, void *win, t_coord a, t_coord b)
{
	int k;

	k = 0;
	while (k < 100)
	{
		mlx_pixel_put(mlx, win, a.x + (k * (b.x - a.x)) / 100, a.y + \
				(k * (b.y - a.y)) / 100, 0x00FFFFFF);
		k++;
	}
}
