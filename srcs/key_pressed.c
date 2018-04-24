/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 05:00:09 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/24 03:03:45 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		zoom(t_win *win, int keycode)
{
	if (keycode == K_MINUS)
	{
		resize_point(&(win->coord_x), -ZOOM);
		resize_point(&(win->coord_y), -ZOOM);
		resize_point(&(win->coord_z), -ZOOM);
	}
	else
	{
		resize_point(&(win->coord_x), ZOOM);
		resize_point(&(win->coord_y), ZOOM);
		resize_point(&(win->coord_z), ZOOM);
	}
}

static void		traslation(t_win *win, int keycode)
{
	if (keycode == K_A)
		traslate_point(&(win->origin), -TRASLATION, 0.0);
	else if (keycode == K_W)
		traslate_point(&(win->origin), 0.0, -TRASLATION);
	else if (keycode == K_D)
		traslate_point(&(win->origin), TRASLATION, 0.0);
	else
		traslate_point(&(win->origin), 0.0, TRASLATION);
}

static void		select_rotation(t_win *win, double x, double y, double z)
{
	rotate_point(&(win->coord_x), x, y, z);
	rotate_point(&(win->coord_y), x, y, z);
	rotate_point(&(win->coord_z), x, y, z);
	win->legend.ang_x = (win->legend.ang_x + (int)x) % 360;
	win->legend.ang_y = (win->legend.ang_y + (int)y) % 360;
	win->legend.ang_z = (win->legend.ang_z + (int)z) % 360;
}

static void		rotate(t_win *win, int keycode)
{
	if (keycode == K_L_ARR)
		select_rotation(win, -ANG, 0.0, 0.0);
	else if (keycode == K_U_ARR)
		select_rotation(win, 0.0, -ANG, 0.0);
	else if (keycode == K_R_ARR)
		select_rotation(win, ANG, 0.0, 0.0);
	else if (keycode == K_POINT)
		select_rotation(win, 0.0, 0.0, -ANG);
	else if (keycode == K_SLASH)
		select_rotation(win, 0.0, 0.0, ANG);
	else
		select_rotation(win, 0.0, ANG, 0.0);
}

int				key_pressed(int keycode, t_win *win)
{
	ft_putstr("\033[1;96mKey pressed: ");
	ft_putnbr(keycode);
	ft_putstr("\033[0m\n");
	if (keycode == K_MINUS || keycode == K_PLUS)
		zoom(win, keycode);
	else if (keycode == K_A || keycode == K_W ||
			keycode == K_D || keycode == K_S)
		traslation(win, keycode);
	else if (keycode == K_L_ARR || keycode == K_U_ARR || keycode == K_R_ARR ||
			keycode == K_D_ARR || keycode == K_POINT || keycode == K_SLASH)
		rotate(win, keycode);
	else if (keycode == K_P1)
		win->legend.p1 = win->legend.p1 ? 0 : 1;
	else if (keycode == K_P2)
		win->legend.p2 = win->legend.p2 ? 0 : 1;
	else if (keycode == K_R)
		restart(win);
	else if (keycode == K_N || keycode == K_M)
		resize_point(&(win->coord_z), keycode == K_N ? -ZOOM : ZOOM);
	else if (keycode == K_ESC)
		end_fdf();
	update_legend(win);
	mlx_destroy_image(win->mlx_id, win->img_ptr);
	line_writter(win);
	return (0);
}
