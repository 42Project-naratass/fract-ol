/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:44:00 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 03:26:52 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

size_t	calc_julia(t_data *img, const int p_x, const int p_y)
{
	double	x;
	double	y;
	size_t	iter;
	t_sqr	sqr;

	x = img->x_min + ((double)p_x / WIDTH) * (img->x_max - img->x_min);
	y = img->y_max - ((double)p_y / HEIGHT) * (img->y_max - img->y_min);
	x = x / img->zoom + img->x_offset;
	y = y / img->zoom + img->y_offset;
	sqr.xsqr = x * x;
	sqr.ysqr = y * y;
	iter = 0;
	while (sqr.xsqr + sqr.ysqr <= 4
		&& iter < img->max_iter)
	{
		y = (x + y) * (x + y) - sqr.xsqr - sqr.ysqr + img->czr ;
		y += img->czi;
		x = sqr.xsqr - sqr.ysqr;
		sqr.xsqr = x * x;
		sqr.ysqr = y * y;
		++iter;
	}
	return (iter);
}
