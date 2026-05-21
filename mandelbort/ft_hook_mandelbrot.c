#include "fractol.h"

int	ft_hook_mandelbrot(void *param)
{
    t_data	*img;

    img = param;
    plot_mandelbrot(img, true);
    return (0);
}
