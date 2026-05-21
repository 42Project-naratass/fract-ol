#include "../fractol.h"

// @param x 	The x coordinate of the mouse.
// @param y 	The y coordinate of the mouse.
// @param zoom	1 for zoom-in, -1 for zoom out.

int	ft_mouse_hook(int mouse_code, int x, int y, void *param)
{
    t_data	*fractol;

    fractol = param;
    if (mouse_code == SCROLL_UP)
		zoom(fractol, x, y, 1);
    else if (mouse_code == SCROLL_DOWN)
		zoom(fractol, x, y, -1);
    plot_mandelbrot(fractol, false);
    return (0);
}
