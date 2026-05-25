/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_mandelbort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:43:49 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 01:43:50 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	plot_mandelbrot(t_data *img)
{
	if (img->curr_pass == 0)
		render_resolution(img, calc_mandelbrot, 16);
	else if (img->curr_pass == 1)
		render_resolution(img, calc_mandelbrot, 8);
	else if (img->curr_pass == 2)
		render_resolution(img, calc_mandelbrot, 4);
	else if (img->curr_pass == 3)
		render_resolution(img, calc_mandelbrot, 2);
	else
		render_resolution(img, calc_mandelbrot, 1);
}
