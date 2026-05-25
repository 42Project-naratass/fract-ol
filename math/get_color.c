/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 02:02:37 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 02:03:43 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	fill_palette_0_to_15(uint32_t *p)
{
	p[0] = 0x000000FF;
	p[1] = 0x111111FF;
	p[2] = 0x222222FF;
	p[3] = 0x333333FF;
	p[4] = 0x444444FF;
	p[5] = 0x555555FF;
	p[6] = 0x666666FF;
	p[7] = 0x777777FF;
	p[8] = 0x888888FF;
	p[9] = 0x999999FF;
	p[10] = 0xAAAAAAFF;
	p[11] = 0xBBBBBBFF;
	p[12] = 0xCCCCCCFF;
	p[13] = 0xDDDDDDFF;
	p[14] = 0xEEEEEEFF;
	p[15] = 0xF7F7F7FF;
}

static void	fill_palette_16_to_31(uint32_t *p)
{
	p[16] = 0xFFFFFFFF;
	p[17] = 0xF0F0F0FF;
	p[18] = 0xE0E0E0FF;
	p[19] = 0xD0D0D0FF;
	p[20] = 0xC0C0C0FF;
	p[21] = 0x21B0B0FF;
	p[22] = 0xA0A0A0FF;
	p[23] = 0x909090FF;
	p[24] = 0x808080FF;
	p[25] = 0x707070FF;
	p[26] = 0x606060FF;
	p[27] = 0x505050FF;
	p[28] = 0x404040FF;
	p[29] = 0x303030FF;
	p[30] = 0x202020FF;
	p[31] = 0x101010FF;
}

uint32_t	get_color(const int iter)
{
	uint32_t	palette[32];
	int			index;

	fill_palette_0_to_15(palette);
	fill_palette_16_to_31(palette);
	index = round(iter / 1.625);
	return (palette[index]);
}
