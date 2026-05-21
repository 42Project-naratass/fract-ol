#include "../fractol.h"

void	plot_mandelbrot(t_data *img)
{
    int	p_x;
    int	p_y;
    int	iter;

    p_x = 0;
    while (p_x < WIDTH - 1)
    {
	p_y = 0;
	while (p_y < HEIGHT - 1)
	{
	   iter = calc_mandelbrot(img, p_x, p_y);
	   if (iter == img->max_iter)
	   {
		my_mlx_pixel_put(img, p_x, p_y, 0x00000000);
		my_mlx_pixel_put(img, p_x + 1, p_y, 0x00000000);
		my_mlx_pixel_put(img, p_x, p_y + 1, 0x00000000);
		my_mlx_pixel_put(img, p_x + 1, p_y + 1, 0x00000000);
	   }
	   else
	   {
	       my_mlx_pixel_put(img, p_x, p_y, get_color(iter));
	       my_mlx_pixel_put(img, p_x + 1, p_y, get_color(iter));
	       my_mlx_pixel_put(img, p_x, p_y + 1, get_color(iter));
	       my_mlx_pixel_put(img, p_x + 1, p_y + 1, get_color(iter));
	   }
	   p_y += 2;
	}
	p_x += 2;
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
