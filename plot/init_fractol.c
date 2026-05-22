#include "../fractol.h"

void	init_fractol(t_data *img)
{
	img->zoom = 0.6;
	img->cx = WIDTH / 2;
	img->cy = HEIGHT / 2;
	img->max_iter = 50;
	img->m_x = 0;
	img->m_y = 0;
	img->curr_pass = 0;
	img->x_offset = -0.5;
	img->y_offset = 0.0; 
}

