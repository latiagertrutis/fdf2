/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 04:43:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/25 04:51:11 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_list_map(t_point *map)
{
	t_point *aux;

	while (map)
	{
		aux = map->next;
		free(map);
		map = aux;
	}
}
