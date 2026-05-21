#include "../fractol.h"

int	calc_mandelbrot(t_data *img, const int p_x, const int p_y) 
{
	double	x;
	double	y;
	int	iter;
	double	x_temp;
	t_complex	complex;

	x = 0;
	y = 0;
	iter = 0;
	complex.real = X_MIN + (p_x / WIDTH) * (X_MAX - X_MIN);
	complex.i = Y_MAX - (p_y / HEIGHT) * (Y_MAX- Y_MIN);
	complex.real = (img->m_x - complex.real) / img->zoom;
	complex.i = (img->m_y - complex.i) / img->zoom;
	while ((x * x) + (y * y) <= 4 && iter < MAX_ITER) // escape time algorithm
	{
		x_temp = (x * x) - (y * y) + complex.real + img->x_offset;
		y = 2 * x * y + complex.i + img->y_offset;
		x = x_temp;
		++iter;
	}
	return (iter);
}
