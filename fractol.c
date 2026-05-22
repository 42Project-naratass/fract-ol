#include "fractol.h"

static void	draw_fractol(t_data *img, char *argv[])
{
    if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	mlx_loop_hook(img->mlx, ft_hook_mandelbrot, img);
}

int	main(int argc, char *argv[])
{
	t_data	img;

	if (argc > 1)
	{
	    init_mlx(&img);
	    init_fractol(&img);
	    mlx_key_hook(img.mlx_win, ft_key_hook, &img);
	    mlx_mouse_hook(img.mlx_win, ft_mouse_hook, &img);
	    mlx_hook(img.mlx_win, 17, 0L, ft_close_win, &img);
	    draw_fractol(&img, argv);
	    mlx_loop(img.mlx);
	}
	return (0);
}

