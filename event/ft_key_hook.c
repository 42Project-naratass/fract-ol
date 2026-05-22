#include "../fractol.h"

int	ft_key_hook(int key_code, void *data)
{
    t_data	*fractal;

    fractal = data;
    if (key_code == ESC)
	exit(1);
    else if (key_code == w || key_code == UP)
	fractal->y_offset -= 0.5 / fractal->zoom;
    else if (key_code == s || key_code == DOWN)
	fractal->y_offset += 0.5 / fractal->zoom;
    else if (key_code == a || key_code == LEFT)
	fractal->x_offset += 0.5 / fractal->zoom;
    else if (key_code == d || key_code == RIGHT)
	fractal->x_offset -= 0.5 / fractal->zoom;
    fractal->need_render = true;
    fractal->curr_pass = 0;
    return (0);
}
