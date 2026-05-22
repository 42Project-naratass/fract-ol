#include "../fractol.h"

size_t	calc_mandelbrot(t_data *img, const int p_x, const int p_y) 
{
	double		x;
	double		y;
	size_t		iter;
	t_complex	complex;
	double		xsqr;
	double		ysqr;

	x = 0;
	y = 0;
	xsqr = 0;
	ysqr = 0;
	iter = 0;
	complex.real = x_min + ((double)p_x / WIDTH) * (x_max - x_min);
	complex.i = y_max - ((double)p_y / HEIGHT) * (y_max - y_min);
	complex.real = (img->m_x - complex.real) / img->zoom;
	complex.i = (img->m_y - complex.i) / img->zoom;
	while (xsqr + ysqr <= 4 && iter < img->max_iter) // escape time algorithm
	{
	    y = (x + y) * (x + y) - xsqr - ysqr;
	    y += complex.i + img->y_offset;
	    x = xsqr - ysqr + complex.real + img->x_offset;
	    xsqr = x * x;
	    ysqr = y * y;
	    ++iter;
	}
	return (iter);
}
