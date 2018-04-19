/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 21:53:34 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/19 06:35:32 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		convert_to_color(int color)
{	
	color *= 35;
	if (color < 0)
	{
		color = -color;
		if (color > 0xFF)
			return (0xFFFF - (color - 0xFF));
		return (0xFF + (color << 8));
	}
	if (color > 0xFF)
		return (0xFF00FF - (color - 0xFF));
	return (0xFF + (color << 16));
}

static int		select_color(t_2dpi inip0, t_2dpi p0, t_2dpi pf)
{
	double dx = labs(pf.x - inip0.x);
	double dy = labs(pf.y - inip0.y);
	double c1 = dx * (double)inip0.x + dy * (double)inip0.y;
	double c2 = dx * (double)pf.x + dy * (double)pf.y;
	double color;
	if (c2 < c1)
	{
		color = c1;
		c1 = c2;
		c2 = color;

		color = p0.z;
		p0.z = pf.z;
		pf.z = color;
	}
	color = dx * p0.x + dy * p0.y;
	if (color <= c1)
		color = p0.z;
	else if (color >= c2)
		color = pf.z;
	else
		color = ((p0.z * (c2 - color) + pf.z * (color - c1)) / (c2 - c1));
	return (convert_to_color(color));
}


void				draw_line(t_win *win, t_2dpi ini_p0, t_2dpi p0, t_2dpi pf)
{
	int dx;
	int dy;
	int err;
	int e2;
	dx = ft_abs((int)pf.x - (int)p0.x);
	dy = ft_abs((int)pf.y - (int)p0.y);
	err = (dx > dy ? dx : -dy) / 2;
	while(1)
	{
//		mlx_pixel_put(win->mlx_id, win->win_id, (int)p0.x, (int)p0.y, select_color(ini_p0, p0, pf));
		if ((p0.x == pf.x && p0.y == pf.y) || p0.x >= W_WIDTH || p0.x < 0 || p0.y >= W_HEIGHT || p0.y < 0)
			break;
		((int *)(win->img))[ft_abs(p0.x) + ft_abs((W_WIDTH * p0.y))] = select_color(ini_p0, p0, pf);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			p0.x += (double)((int)p0.x < (int)pf.x ? 1 : -1);
		}
		if (e2 < dy)
		{
			err += dx;
			p0.y += (double)((int)p0.y < (int)pf.y ? 1 : -1);
		}
	}
}
