/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:59:28 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 01:59:43 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_data *img)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	img->mlx = mlx;
	mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Fract-ol");
	img->mlx_win = mlx_win;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}
