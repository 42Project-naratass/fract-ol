/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:56:53 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 02:05:57 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_key_hook(int key_code, void *data)
{
	t_data	*fractal;

	fractal = data;
	if (key_code == ESC)
	{
		ft_close_win(fractal);
		exit(1);
	}
	else if (key_code == W || key_code == UP)
		fractal->y_offset += 0.5 / fractal->zoom;
	else if (key_code == S || key_code == DOWN)
		fractal->y_offset -= 0.5 / fractal->zoom;
	else if (key_code == A || key_code == LEFT)
		fractal->x_offset -= 0.5 / fractal->zoom;
	else if (key_code == D || key_code == RIGHT)
		fractal->x_offset += 0.5 / fractal->zoom;
	else if (key_code == R)
		init_fractol(fractal);
	else
		return (0);
	fractal->need_render = true;
	fractal->curr_pass = 0;
	return (0);
}
