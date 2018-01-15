/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:51:59 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/15 17:58:49 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	t_coord		fsize;
	t_coord		wsize;
	int			maxvalue;
	char		***values;
}				t_map;

int				ft_map_init(t_map *map, char *file_name, int *stats);

void			ft_drawline(t_map map, t_coord a, t_coord b);
void			ft_readanddraw(t_map map, int *stats, int *fd);
void			ft_readpoints(t_map map, int *stats, char **s);
void			ft_setpoints(t_coord *p, int *stats, t_coord z, char ***array);

#endif
