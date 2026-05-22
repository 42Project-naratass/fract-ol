#include "fractol.h"
#include "minilibx/mlx.h"

int	main(void)
{
	t_data	img;

	init(&img);
	mlx_key_hook(img.mlx_win, ft_key_hook, &img);
	mlx_mouse_hook(img.mlx_win, ft_mouse_hook, &img);
	mlx_hook(img.mlx_win, 17, 0L, ft_close_win, &img);
	mlx_loop_hook(img.mlx, ft_hook_mandelbrot, &img);
	mlx_loop(img.mlx);
}

