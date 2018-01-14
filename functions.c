/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:54:53 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/14 19:17:00 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
