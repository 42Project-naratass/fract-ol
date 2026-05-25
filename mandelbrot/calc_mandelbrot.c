/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:33:11 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 03:51:00 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

size_t	calc_mandelbrot(t_data *img, const int p_x, const int p_y)
{
	double		x;
	double		y;
	size_t		iter;
	t_complex	z;
	t_sqr		sqr;

	x = 0;
	y = 0;
	sqr.xsqr = 0;
	sqr.ysqr = 0;
	iter = 0;
	z.real = img->x_min + ((double)p_x / WIDTH) * (img->x_max - img->x_min);
	z.i = img->y_max - ((double)p_y / HEIGHT) * (img->y_max - img->y_min);
	z.real = ((z.real) / img->zoom) + img->x_offset;
	z.i = ((z.i) / img->zoom) + img->y_offset;
	while (sqr.xsqr + sqr.ysqr <= 4 && iter < img->max_iter)
	{
		y = (x + y) * (x + y) - sqr.xsqr - sqr.ysqr;
		y += z.i;
		x = sqr.xsqr - sqr.ysqr + z.real;
		sqr.xsqr = x * x;
		sqr.ysqr = y * y;
		iter++;
	}
	return (iter);
}
