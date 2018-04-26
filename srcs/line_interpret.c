/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_interpret.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 03:30:48 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/26 07:46:55 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	adjust_color(double z, t_win *win)
{
	if (z > 14.0)
		return (z * (14.0 / (double)win->map_max));
	else if (z < -14.0)
		return (z * (14.0 / -(double)win->map_min));
	else
		return (z);
}

void			line_interpret(t_win *win, t_2dpi p0, t_2dpi pf)
{
	p0.z = adjust_color(p0.z, win);
	pf.z = adjust_color(pf.z, win);
	if (p0.x >= 0 && p0.x < W_WIDTH && p0.y >= 0 && p0.y < W_HEIGHT)
		draw_line(win, p0, p0, pf);
	else if (pf.x >= 0 && pf.x < W_WIDTH && pf.y >= 0 && pf.y < W_HEIGHT)
		draw_line(win, pf, pf, p0);
}
