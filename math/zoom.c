#include "../fractol.h"

void	zoom(t_data *fractol, const int x, const int y, const int zoom)
{
	double	zoom_multiply;

	(void)x;
	(void)y;
	zoom_multiply = 0.85;
	if (zoom == -1)
	{
		fractol->zoom *= zoom_multiply;
	}
	else if (zoom == 1)
	{
		fractol->zoom /= zoom_multiply;
	}
	else
		return ;
}
