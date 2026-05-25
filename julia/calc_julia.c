/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:44:00 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 02:22:01 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

size_t	calc_julia(t_data *img, const int p_x, const int p_y)
{
	double	x;
	double	y;
	size_t	iter;
	t_sqr	sqr;

	x = img->x_min + ((double)p_x / WIDTH) * (img->x_max - img->x_max);
	y = img->y_max - ((double)p_y / HEIGHT) * (img->y_max - img->y_min);
	x = (x) / img->zoom;
	y = (y + img->y_offset) / img->zoom;
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
