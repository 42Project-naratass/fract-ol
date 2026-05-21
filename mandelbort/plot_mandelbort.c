#include "../fractol.h"

void	plot_mandelbrot(t_data *img)
{
    if (img->curr_pass == 0)
	reso_x8(img);
    else if (img->curr_pass == 1)
	reso_x4(img);
    else if (img->curr_pass == 2)
	reso_x2(img);
    else
	reso_x1(img);
}
