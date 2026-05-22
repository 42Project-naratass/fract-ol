#include "../fractol.h"

void	init(t_data *img)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	img->mlx = mlx;
	mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Fract-ol");
	img->mlx_win = mlx_win;
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	img->zoom = 0.6;
	img->cx = WIDTH / 2;
	img->cy = HEIGHT / 2;
	img->max_iter = MAX_ITER;
	img->m_x = 0;
	img->m_y = 0;
	img->curr_pass = 0;
	img->x_offset = -0.5;
	img->y_offset = 0.0; 
}
