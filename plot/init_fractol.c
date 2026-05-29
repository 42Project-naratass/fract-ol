/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:57:19 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 03:55:31 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <sys/time.h>

void	init_fractol(t_data *img)
{
	img->need_render = true;
	img->zoom = 0.6;
	img->max_iter = 50;
	img->c_x = 0;
	img->c_y = 0;
	img->curr_pass = 0;
	img->x_offset = 0.15;
	img->y_offset = 0.0;
	img->x_min = (WIDTH / 1200.0 * -1);
	img->x_max = (WIDTH / 1200.0);
	img->y_min = (HEIGHT / 1200.0 * -1);
	img->y_max = (HEIGHT / 1200.0);
}
