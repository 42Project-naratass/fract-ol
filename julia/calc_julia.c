#include "../fractol.h"

size_t	calc_julia(t_data *img, const int p_x, const int p_y)
{
	double	x;
	double	y;
	size_t	iter;
	double	xsqr;
	double	ysqr;

	x = X_MIN + ((double)p_x / WIDTH) * (X_MAX - X_MIN) + img->x_offset;
	y = Y_MAX - ((double)p_y / HEIGHT) * (Y_MAX - Y_MIN) + img->y_offset;
	x = x / img->zoom;
	y = y / img->zoom;
	xsqr = x * x;
	ysqr = y * y;
	iter = 0;
	while (xsqr + ysqr <= 4 && iter < img->max_iter) // escape time algorithm
	{
		y = (x + y) * (x + y) - xsqr - ysqr + img->czr ;
		y += img->czi;
		x = xsqr - ysqr;
		xsqr = x * x;
		ysqr = y * y;
		++iter;
	}
	return (iter);
}
