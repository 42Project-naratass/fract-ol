
#include "../fractol.h"

static void	ft_loop(t_data *img, const int p_x, const int p_y, uint32_t color)
{
    size_t	i;
    size_t	j;

    i = 0;
    j = 0;
    while (i < 16)
    {
	j = 0;
	while (j < 16 && p_x + i < WIDTH && p_y + j < HEIGHT)
	{
	    my_mlx_pixel_put(img, p_x + i, p_y + j, color);
	    ++j;
	}
	++i;
    }
}

void	reso_x16(t_data *img)
{
    int		p_x;
    int		p_y;
    size_t	iter;

    p_x = 0;
    while (p_x < WIDTH - 15)
    {
	p_y = 0;
	while (p_y < HEIGHT - 15)
	{
	   iter = calc_mandelbrot(img, p_x, p_y);
	   if (iter == img->max_iter)
	       ft_loop(img, p_x, p_y, 0x00000000);
	   else
	       ft_loop(img, p_x, p_y, get_color(iter));
	   p_y += 4;
	}
	p_x += 4;
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
