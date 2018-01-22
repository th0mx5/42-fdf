/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:51:59 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/22 20:18:54 by thbernar         ###   ########.fr       */
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
	int			z;
}				t_coord;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	t_coord		fsize;
	char		*fname;
	t_coord		wsize;
	int			maxvalue;
	int			**values;
	t_coord		**values3d;
	double		zoom;
	int			xshift;
	int			yshift;
}				t_map;

int				ft_map_init(t_map *map, char *file_name);
int				ft_map_counts(t_map *map);
int				ft_map_allocvalues(t_map *map);
int				ft_map_writevalues(t_map *map);
int				ft_map_calc3Dvalues(t_map *map);

void			ft_drawline(t_map map, t_coord a, t_coord b);
void			ft_win_draw(t_map map);
void			ft_win_clear(t_map map);

int				ft_keyhooked(int keycode, t_map *map);

#endif
