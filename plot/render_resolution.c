/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:24:28 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 02:14:57 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ft_loop(t_data *img, t_pcor pcor, uint32_t color, size_t reso_scale)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < reso_scale)
	{
		j = 0;
		while (j < reso_scale && pcor.p_x + i < WIDTH && pcor.p_y + j < HEIGHT)
		{
			my_mlx_pixel_put(img, pcor.p_x + i, pcor.p_y + j, color);
			++j;
		}
		++i;
	}
}

void	render_resolution(t_data *img, size_t(*fractol)(t_data*, int, int),
							size_t reso_scale)
{
	int		p_x;
	int		p_y;
	size_t	iter;
	t_pcor	pcor;

	p_x = 0;
	while (p_x < WIDTH - reso_scale)
	{
		p_y = 0;
		while (p_y < HEIGHT - reso_scale)
		{
			iter = fractol(img, p_x, p_y);
			pcor.p_x = p_x;
			pcor.p_y = p_y;
			if (iter == img->max_iter)
				ft_loop(img, pcor, 0x00000000, reso_scale);
			else
				ft_loop(img, pcor, get_color(iter), reso_scale);
			p_y += reso_scale;
		}
		p_x += reso_scale;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
