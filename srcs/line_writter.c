/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_writter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:56:28 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/24 01:22:44 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_2dp	esc_prod(t_2dp v, double p)
{
	v.x *= p;
	v.y *= p;
	v.z *= p;
	return (v);
}

static t_2dpi	vectadd(t_2dp origin, t_2dp v1, t_2dp v2, t_2dp v3)
{
	t_2dpi aux;

	aux.x = lround(origin.x + v1.x + v2.x + v3.x);
	aux.y = lround(origin.y + v1.y + v2.y + v3.y);
	aux.z = origin.z + v1.z + v2.z + v3.z;
	return (aux);
}

static t_2dpi	new_point(t_win *win, t_2dpi p0)
{
	t_2dpi pf;

	pf = vectadd(win->origin, esc_prod(win->coord_x, (double)p0.x),
	esc_prod(win->coord_y, (double)p0.y), esc_prod(win->coord_z, (double)p0.z));
	if (win->legend.p1 || win->legend.p2)
		project_point(win, &pf);
	pf.z = (int)p0.z;
	return (pf);
}

void			line_writter(t_win *win)
{
	int i;
	int j;

	create_image(win);
	i = 0;
	while (i < win->map_wid)
	{
		j = 0;
		while (j < win->map_hei)
		{
			if (j + 1 < win->map_hei)
				line_interpret(win, new_point(win, win->map[i][j]),
								new_point(win, win->map[i][j + 1]));
			if (i + 1 < win->map_wid)
				line_interpret(win, new_point(win, win->map[i][j]),
								new_point(win, win->map[i + 1][j]));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(win->mlx_id, win->win_id, win->img_ptr, 0, 0);
}
