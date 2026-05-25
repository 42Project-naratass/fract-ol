#include "fractol.h"

const double x_min = WIDTH / 1200.0 * -1;
const double x_max = WIDTH / 1200.0;
const double y_min = HEIGHT / 1200.0 * -1;
const double y_max = HEIGHT / 1200.0;

static void	invalid_input(char *argv[])
{
    if (ft_strncmp(argv[1], "mandelbrot", 10) != 0 &&
	ft_strncmp(argv[1], "julia", 6) != 0)
    {
	ft_printf("error: invalid format\nUse following format:\n\
./fractol mandelbrot\n\
./fractol julia\n");
	exit(0);
    }
}

static void	draw_fractol(t_data *img, char *argv[])
{
    if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	mlx_loop_hook(img->mlx, ft_hook_mandelbrot, img);
    else if (ft_strncmp(argv[1], "julia", 5) == 0)
	mlx_loop_hook(img->mlx, ft_hook_julia, img);
}

int	main(int argc, char *argv[])
{
	t_data	img;

	if (argc > 1)
	{
	    invalid_input(argv);
	    init_mlx(&img);
	    init_fractol(&img);
	    mlx_key_hook(img.mlx_win, ft_key_hook, &img);
	    mlx_mouse_hook(img.mlx_win, ft_mouse_hook, &img);
	    mlx_hook(img.mlx_win, 17, 0L, ft_close_win, &img);
	    draw_fractol(&img, argv);
	    mlx_loop(img.mlx);
	}
	else
	    ft_printf("error: invalid format\nUse following format:\n\
./fractol mandelbrot\n\
./fractol julia\n");
	return (0);
}

