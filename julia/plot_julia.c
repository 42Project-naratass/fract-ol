/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:43:54 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 01:43:54 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	plot_julia(t_data *img)
{
	if (img->curr_pass == 0)
		render_resolution(img, calc_julia, 16);
	else if (img->curr_pass == 1)
		render_resolution(img, calc_julia, 8);
	else if (img->curr_pass == 2)
		render_resolution(img, calc_julia, 4);
	else if (img->curr_pass == 3)
		render_resolution(img, calc_julia, 2);
	else
		render_resolution(img, calc_julia, 1);
}
