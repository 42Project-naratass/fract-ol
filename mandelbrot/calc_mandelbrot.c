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
	complex.real = X_MIN + ((double)p_x / WIDTH) * (X_MAX - X_MIN);
	complex.i = Y_MAX - ((double)p_y / HEIGHT) * (Y_MAX - Y_MIN);
	complex.real = ((complex.real) / img->zoom) + img->x_offset;
	complex.i = ((complex.i) / img->zoom) + img->y_offset;
	while (xsqr + ysqr <= 4 && iter < img->max_iter) // escape time algorithm
	{
		y = (x + y) * (x + y) - xsqr - ysqr;
		y += complex.i;
		x = xsqr - ysqr + complex.real;
		xsqr = x * x;
		ysqr = y * y;
		++iter;
	}
	return (iter);
}
