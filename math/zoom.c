/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 02:03:59 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 02:04:00 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom(t_data *fractol, const int x, const int y, const int zoom)
{
	double	zoom_multiply;

	(void)x;
	(void)y;
	zoom_multiply = 0.85;
	if (zoom == -1)
	{
		fractol->zoom *= zoom_multiply;
	}
	else if (zoom == 1)
	{
		fractol->zoom /= zoom_multiply;
	}
	else
		return ;
}
