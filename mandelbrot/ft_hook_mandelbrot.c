/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:43:46 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 01:44:48 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_hook_mandelbrot(void *param)
{
	t_data	*img;

	img = param;
	if (img->need_render)
	{
		img = param;
		plot_mandelbrot(img);
		img->curr_pass++;
		if (img->curr_pass > 4)
		{
			img->need_render = false;
			img->curr_pass = 0;
		}
	}
	return (0);
}
