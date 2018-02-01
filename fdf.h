/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:51:59 by thbernar          #+#    #+#             */
/*   Updated: 2018/02/01 20:54:20 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "minilibx/mlx.h"
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
	void		*img;
	t_coord		fsize;
	char		*fname;
	t_coord		wsize;
	int			maxvalue;
	t_coord		*values;
	int			*img_data;
	double		zoom;
	int			xshift;
	int			yshift;
	int			zshift;
}				t_map;

void			ft_map_init(t_map *map, char *file_name);
void			ft_map_counts(t_map *map);
int				ft_map_allocvalues(t_map *map);
void			ft_map_writevalues(t_map *map);
int				ft_map_calc3dvalues(t_map *map);

void			ft_drawline(t_map map, t_coord a, t_coord b);
void			ft_win_draw(t_map *map);

void			ft_free_strsplit(char **array);
void			ft_img_putpixel(t_map *map, t_coord p, int color);

int				ft_keyhooked(int keycode, t_map *map);

t_coord			ft_transform(t_map *map, t_coord a);
void			ft_printcontrols(void);
void			ft_error(char *s);

#endif
