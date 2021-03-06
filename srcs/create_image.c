/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 22:10:45 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/26 06:48:15 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	create_image(t_win *win)
{
	int		bit_per_pixel;
	int		size_line;
	int		endian;

	bit_per_pixel = sizeof(int) * 8;
	size_line = W_WIDTH * sizeof(int);
	endian = 0;
	if (!(win->img_ptr = mlx_new_image(win->mlx_id, W_WIDTH, W_HEIGHT)))
		exit_failure("Can not create image");
	if (!(win->img =
		mlx_get_data_addr(win->img_ptr, &bit_per_pixel, &size_line, &endian)))
		exit_failure("Can not obtain image adress");
}

/*
**	To add background image
**
**	int		width = W_WIDTH;
**	int		height = W_HEIGHT;
**
**	if (!(win->img_ptr = mlx_xpm_file_to_image
**		(win->mlx_id, "guille.xpm", &width, &height)))
**		exit_failure("Can not create image");
*/
