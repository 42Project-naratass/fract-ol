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

void	init_fractol(t_data *img)
{
	img->need_render = true;
	img->zoom = 1.0;
	img->max_iter = 50;
	img->c_x = 0;
	img->c_y = 0;
	img->curr_pass = 0;
	img->x_offset = -0.5;
	img->y_offset = 0.0;
	img->x_min = -2.0; 
	img->x_max = 2.0;
	img->y_min = (HEIGHT / WIDTH) * -2.0;
	img->y_max = (HEIGHT / WIDTH) * 2.0;
}
