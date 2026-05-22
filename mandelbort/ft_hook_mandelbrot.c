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
