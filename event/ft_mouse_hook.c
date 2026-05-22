#include "../fractol.h"

// @param x 	The x coordinate of the mouse.
// @param y 	The y coordinate of the mouse.
// @param zoom	1 for zoom-in, -1 for zoom out.

int	ft_mouse_hook(int mouse_code, int x, int y, void *param)
{
    t_data	*fractol;

    fractol = param;
    if (mouse_code == SCROLL_UP)
    {
	if (fractol->zoom >= MAX_ZOOM)
	    return (0);
	zoom(fractol, x, y, 1);
    }
    else if (mouse_code == SCROLL_DOWN)
	zoom(fractol, x, y, -1);
    if (fractol->zoom > 0 && fractol->zoom < 50)
	fractol->max_iter = 50;
    else if (fractol->zoom >= 51 && fractol->zoom < 10000)
	fractol->max_iter = 75;
    else if (fractol->zoom >= 10001 && fractol->zoom < 100000)
	fractol->max_iter = 100;
    else if (fractol->zoom >= 100001 && fractol->zoom < 1000000)
	fractol->max_iter = 125;
    else if (fractol->zoom >= 1000001)
	fractol->max_iter = MAX_ITER;
    fractol->need_render = true;
    fractol->curr_pass = 0;
    return (0);
}
