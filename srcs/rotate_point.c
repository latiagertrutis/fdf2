/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 04:27:31 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/24 01:52:09 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		rx(double ang, t_2dp *p)
{
	double aux1;
	double aux2;
	double coseno;
	double seno;

	coseno = cos(ang);
	seno = sin(ang);
	aux1 = (double)(p->y) * coseno - (double)(p->z) * seno;
	aux2 = (double)(p->y) * seno + (double)(p->z) * coseno;
	p->y = aux1;
	p->z = aux2;
}

static void		ry(double ang, t_2dp *p)
{
	double aux1;
	double aux2;
	double coseno;
	double seno;

	coseno = cos(ang);
	seno = sin(ang);
	aux1 = (double)(p->z) * coseno - (double)(p->x) * seno;
	aux2 = (double)(p->z) * seno + (double)(p->x) * coseno;
	p->z = aux1;
	p->x = aux2;
}

static void		rz(double ang, t_2dp *p)
{
	double aux1;
	double aux2;
	double coseno;
	double seno;

	coseno = cos(ang);
	seno = sin(ang);
	aux1 = (p->x) * coseno - (p->y) * seno;
	aux2 = (p->x) * seno + (p->y) * coseno;
	p->x = aux1;
	p->y = aux2;
}

static double	to_rad(double ang)
{
	return (ang * (M_PI / 180.0));
}

void			rotate_point(t_2dp *p, double x, double y, double z)
{
	rx(to_rad(x), p);
	ry(to_rad(y), p);
	rz(to_rad(z), p);
}
