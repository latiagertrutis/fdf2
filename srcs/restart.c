/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 23:14:34 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/23 23:53:07 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	ini_size(t_win *win)
{
	double x;

	x = ((double)W_WIDTH - 1.0) / ((double)win->map_wid);
	if (x * (double)win->map_hei <= (double)W_HEIGHT)
		return (x);
	return (((double)W_HEIGHT - 1.0) / ((double)win->map_hei));
	
}

void	restart(t_win *win)
{	
	win->coord_x.x = ini_size(win);
	win->coord_x.y = 0.0;
	win->coord_x.z = 0.0;
	win->coord_y.x = 0.0;
	win->coord_y.y = win->coord_x.x;
	win->coord_y.z = 0.0;
	win->coord_z.x = 0.0;
	win->coord_z.y = 0.0;
	win->coord_z.z = win->coord_x.x;
	win->origin.x = 0.0;
	win->origin.y = 0.0;
	win->origin.z = 0.0;
}
