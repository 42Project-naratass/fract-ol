#include "../fractol.h"

int	calc_mandelbrot(t_data *img, const int p_x, const int p_y) 
{
	double		x;
	double		y;
	int		iter;
	t_complex	complex;
	double		xsqr;
	double		ysqr;

	x = 0;
	y = 0;
	xsqr = x;
	ysqr = y;
	iter = 0;
	complex.real = X_MIN + (p_x / WIDTH) * (X_MAX - X_MIN);
	complex.i = Y_MAX - (p_y / HEIGHT) * (Y_MAX- Y_MIN);
	complex.real = (img->m_x - complex.real) / img->zoom;
	complex.i = (img->m_y - complex.i) / img->zoom;
	while (xsqr + ysqr <= 4 && iter < MAX_ITER) // escape time algorithm
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
