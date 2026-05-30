/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:43:28 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 01:56:45 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	zoom_at_mouse(t_data *fractol, double new_zoom,
							int mouse_x, int mouse_y)
{
	double	fx;
	double	fy;

	fx = fractol->x_min + ((double)mouse_x / WIDTH)
		* (fractol->x_max - fractol->x_min);
	fy = fractol->y_max - ((double)mouse_y / HEIGHT)
		* (fractol->y_max - fractol->y_min);
	fractol->x_offset = (fx / fractol->zoom + fractol->x_offset)
		- (fx / new_zoom);
	fractol->y_offset = (fy / fractol->zoom + fractol->y_offset)
		- (fy / new_zoom);
	fractol->zoom = new_zoom;
}

static void	check_zoom_level(t_data *fractol)
{
	if (fractol->zoom > 0 && fractol->zoom < 50)
		fractol->max_iter = 50;
	else if (fractol->zoom < 10000)
		fractol->max_iter = 75;
	else if (fractol->zoom < 100000)
		fractol->max_iter = 100;
	else if (fractol->zoom < 1000000)
		fractol->max_iter = 125;
	else if (fractol->zoom >= 1000001)
		fractol->max_iter = MAX_ITER;
}

// @param x 	The x coordinate of the mouse.
// @param y 	The y coordinate of the mouse.
// @param zoom	1 for zoom-in, -1 for zoom out.

int	ft_mouse_hook(int mouse_code, int x, int y, void *param)
{
	t_data	*fractol;

	fractol = param;
	if (mouse_code == SCROLL_UP)
	{
		if (fractol->zoom >= MAX_ZOOM)
			return (0);
		zoom_at_mouse(fractol, fractol->zoom * 1.1, x, y);
	}
	else if (mouse_code == SCROLL_DOWN)
	{
		if (fractol->zoom <= 0.05)
			return (0);
		zoom_at_mouse(fractol, fractol->zoom * 0.85, x, y);
	}
	check_zoom_level(fractol);
	fractol->need_render = true;
	fractol->curr_pass = 0;
	return (0);
}
