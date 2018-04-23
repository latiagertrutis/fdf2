/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 04:46:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/23 23:45:20 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/fdf.h"


void	project_point(t_win *win, t_2dpi *p)
{
	t_2dpi p0;

	p0 = *p;
	if (win->legend.p1)
	{
		p->x = 1000.0 * (p->x / (2000.0 - p->z));
		p->y = 1000.0 *(p->y / (2000.0 - p->z));
	}
	if (win->legend.p2)
	{
		p->x = (int)((sqrt(2.0) / 2.0) * ((double)p0.x - (double)p0.y));
		p->y = (int)((sqrt(2.0 / 3.0) * (double)p0.z) - ((1.0 / sqrt(6.0)) * ((double)p0.x + (double)p0.y)));
	}
}
