/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:51:59 by thbernar          #+#    #+#             */
/*   Updated: 2018/01/15 15:51:31 by thbernar         ###   ########.fr       */
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
void	ft_readanddraw(void *mlx, void *win, int *stats, int *fd);
void	ft_readpoints(void *mlx, void *win, int *stats, char **s);
void	ft_setpoints(t_coord *p, int *stats, int i, int j, char ***array);

#endif
