#include "../fractol.h"

static void	ft_loop(t_data *img, int p_x, int p_y, uint32_t color, size_t reso_scale)
{
    size_t	i;
    size_t	j;

    i = 0;
    j = 0;
    while (i < reso_scale)
    {
	j = 0;
	while (j < reso_scale && p_x + i < WIDTH && p_y + j < HEIGHT)
	{
	    my_mlx_pixel_put(img, p_x + i, p_y + j, color);
	    ++j;
	}
	++i;
    }
}

void	reso_scale(t_data *img, size_t(*fractol)(t_data*, int, int), size_t reso_scale)
{
    int		p_x;
    int		p_y;
    size_t	iter;

    p_x = 0;
    while (p_x < WIDTH - reso_scale - 1)
    {
	p_y = 0;
	while (p_y < HEIGHT - reso_scale - 1)
	{
	   iter = fractol(img, p_x, p_y);
	   if (iter == img->max_iter)
	       ft_loop(img, p_x, p_y, 0x00000000, reso_scale);
	   else
	       ft_loop(img, p_x, p_y, get_color(iter), reso_scale);
	   p_y += reso_scale;
	}
	p_x += reso_scale;
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
