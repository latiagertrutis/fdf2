/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_legend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 23:39:34 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/24 02:03:28 by mrodrigu         ###   ########.fr       */
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

static void		put_max_min(t_win *win, void *w_id)
{
	if (win->map_max == win->map_min)
		mlx_string_put(win->mlx_id, w_id, 63, 19 + (14 - win->map_max) * 5,
						convert_to_color(win->map_max), "<-FLOOR");
	else
	{
		if (win->map_max < 14)
			mlx_string_put(win->mlx_id, w_id, 63, 19 + (14 - win->map_max) * 5,
							convert_to_color(win->map_max), "<-MAX");
		else if (win->map_max >= 14)
			mlx_string_put(win->mlx_id, w_id, 63, 19, 0xFF0000, "<-MAX");
		if (win->map_min > -14)
			mlx_string_put(win->mlx_id, w_id, 63, 89 - win->map_min * 5,
							convert_to_color(win->map_min), "<-MIN");
		else if (win->map_min <= -14)
			mlx_string_put(win->mlx_id, w_id, 63, 159, 0x00FF00, "<-MIN");
	}
	mlx_string_put(win->mlx_id, w_id, 130, 19, 0xFFFFFF, "Max: ");
	mlx_string_put(win->mlx_id, w_id, 175, 19, 0xFFFFFF, ft_itoa(win->map_max));
	mlx_string_put(win->mlx_id, w_id, 130, 40, 0xFFFFFF, "Min: ");
	mlx_string_put(win->mlx_id, w_id, 175, 40, 0xFFFFFF, ft_itoa(win->map_min));
}

static void		put_color(t_win *win, void *id)
{
	int		color;
	int		i;
	int		j;

	i = 20;
	j = 30;
	color = 14;
	while (color >= -14)
	{
		i = 20;
		while (i < 61)
		{
			mlx_pixel_put(win->mlx_id, id, i, j, convert_to_color(color));
			mlx_pixel_put(win->mlx_id, id, i, j + 1, convert_to_color(color));
			mlx_pixel_put(win->mlx_id, id, i, j + 2, convert_to_color(color));
			mlx_pixel_put(win->mlx_id, id, i, j + 3, convert_to_color(color));
			mlx_pixel_put(win->mlx_id, id, i, j + 4, convert_to_color(color));
			i++;
		}
		j += 5;
		color--;
	}
}

static void		background(t_win *win, void *id)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 300)
	{
		j = 0;
		while (j < 500)
			mlx_pixel_put(win->mlx_id, id, i, j++, 0x696969);
		i++;
	}
}

void			put_legend(t_win *win)
{
	if (!(win->legend.win_id = mlx_new_window(win->mlx_id, 300, 500, "Legend")))
		exit_failure("Can not create window");
	success("Window created");
	background(win, win->legend.win_id);
	put_color(win, win->legend.win_id);
	put_max_min(win, win->legend.win_id);
	mlx_string_put(win->mlx_id, win->legend.win_id,
					20, 190, 0x00b2b2, "TRASLATION:");
	mlx_string_put(win->mlx_id, win->legend.win_id,
					20, 210, 0xFFFFFF, "'A' - 'W' - 'S' - 'D'");
	mlx_string_put(win->mlx_id, win->legend.win_id,
					20, 230, 0x00b2b2, "ROTATION:");
	mlx_string_put(win->mlx_id, win->legend.win_id,
					20, 250, 0xFFFFFF, "X: LEFT ARROW - RIGHT ARROW");
	mlx_string_put(win->mlx_id, win->legend.win_id,
					20, 270, 0xFFFFFF, "Y: UP ARROW - DOWN ARROW");
	mlx_string_put(win->mlx_id, win->legend.win_id,
					20, 290, 0xFFFFFF, "Z: '.' - '/'");
	mlx_string_put(win->mlx_id, win->legend.win_id,
					20, 310, 0x00b2b2, "SIZE:");
	mlx_string_put(win->mlx_id, win->legend.win_id,
					20, 330, 0xFFFFFF, "'-' - '='");
	update_legend(win);
}
