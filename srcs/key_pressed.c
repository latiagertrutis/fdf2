/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 05:00:09 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/21 04:46:29 by mrodrigu         ###   ########.fr       */
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
	mlx_destroy_image(win->mlx_id, win->img_ptr);
	line_writter(win);
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
	mlx_destroy_image(win->mlx_id, win->img_ptr);
	line_writter(win);
}

static void		select_rotation(t_win *win, double x, double y, double z)
{
	rotate_point(&(win->coord_x), x, y, z);
	rotate_point(&(win->coord_y), x, y, z);
	rotate_point(&(win->coord_z), x, y, z);
	win->legend.ang_x = (int)(win->legend.ang_x + x) % 360;
	win->legend.ang_y = (int)(win->legend.ang_y + y) % 360;
	win->legend.ang_z = (int)(win->legend.ang_z + z) % 360;
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
	mlx_destroy_image(win->mlx_id, win->img_ptr);
	update_legend(win);
	line_writter(win);
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
	else if (keycode == K_ESC)
	{
		ft_putstr("\033[1;95mLeaving the program\n¯\\_(ツ)_/¯\n\033[0m");
		exit(0);
	}
	return (0);
}
