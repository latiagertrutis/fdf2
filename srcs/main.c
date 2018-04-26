/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 04:10:59 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/26 07:04:35 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	void	*id;
	t_win	*win;
	t_point	*map;

	if (ac != 2)
		exit_failure("Wrong number of arguments");
	map = input_reader(av[1]);
	success("Map loaded");
	print_map(map);
	if (!(id = mlx_init()))
		exit_failure("mlx_init failure");
	win = window(id, map);
	hooks(win);
	mlx_loop(id);
	return (0);
}
