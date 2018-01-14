/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:51:59 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/14 20:23:55 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include <stdio.h>
#include "mlx.h"
#include "libft/libft.h"

typedef struct t_coord t_coord;
struct t_coord
{
	int x;
	int y;
};
void	ft_checkfilestats(int fd, int *stats);
void	ft_drawline(void *mlx, void *win, t_coord a, t_coord b);
void	ft_draw(void *mlx, void *win, int *fd, t_coord wsize, int *file_stats);
#endif
