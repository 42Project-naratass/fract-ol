#include "../fractol.h"

size_t	calc_julia(t_data *img, const int p_x, const int p_y)
{
	double		x;
	double		y;
	size_t		iter;
	double		xsqr;
	double		ysqr;

	x = x_min + ((double)p_x / WIDTH) * (x_max - x_min);
	y = y_max - ((double)p_y / HEIGHT) * (y_max - y_min);
	x = (img->m_x - x) / img->zoom;
	y = (img->m_y - y) / img->zoom;
	xsqr = x * x;
	ysqr = y * y;
	iter = 0;
	while (xsqr + ysqr <= 4 && iter < img->max_iter) // escape time algorithm
	{
	    y = (x + y) * (x + y) - xsqr - ysqr;
	    y += img->czi + img->y_offset;
	    x = xsqr - ysqr + img->czr + img->x_offset;
	    xsqr = x * x;
	    ysqr = y * y;
	    ++iter;
	}
	return (iter);
}
