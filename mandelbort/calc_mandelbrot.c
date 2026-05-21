#include "../fractol.h"

int	calc_mandelbrot(t_data *img, t_complex complex) 
{
	double	x;
	double	y;
	int		iter;
	double	x_temp;

	x = 0;
	y = 0;
	iter = 0;
	while ((x * x) + (y * y) <= 4 && iter < MAX_ITER) // escape time algorithm
	{
		x_temp = (x * x) - (y * y) + complex.real + img->x_offset;
		y = 2 * x * y + complex.i + img->y_offset;
		x = x_temp;
		iter++;
	}
	return (iter);
}
