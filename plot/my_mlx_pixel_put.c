/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:57:34 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 01:58:28 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, const int p_x, const int p_y, int color)
{
	char	*dst;

	if ((p_x < 0 || p_x > WIDTH) || (p_y < 0 || p_y > HEIGHT))
		return ;
	dst = data->addr + (p_y * data->line_length + p_x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
