#include "../fractol.h"

void	plot_mandelbrot(t_data *img)
{
    if (img->curr_pass == 0)
	reso_scale(img, calc_mandelbrot, 16);
    else if (img->curr_pass == 1)
	reso_scale(img, calc_mandelbrot, 8);
    else if (img->curr_pass == 2)
	reso_scale(img, calc_mandelbrot, 4);
    else if (img->curr_pass == 3)
	reso_scale(img, calc_mandelbrot, 2);
    else
	reso_scale(img, calc_mandelbrot, 1);
}
