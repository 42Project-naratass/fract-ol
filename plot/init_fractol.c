/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:57:19 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 03:23:47 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <sys/time.h>

static double	get_random_value()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	unsigned long val = tv.tv_usec % 1000000;
	return ((double)val / 1000000.0);
}

void	init_fractol(t_data *img)
{
	img->czr = get_random_value() - 0.8;
	img->zoom = 0.6;
	img->max_iter = 50;
	img->c_x = 0;
	img->c_y = 0;
	img->curr_pass = 0;
	img->x_offset = -0.5;
	img->y_offset = 0.0;
	img->x_min = (WIDTH / 1200.0 * -1);
	img->x_max = (WIDTH / 1200.0);
	img->y_min = (HEIGHT / 1200.0 * -1);
	img->y_max = (HEIGHT / 1200.0);
	img->czi = get_random_value() - 0.8;
}
