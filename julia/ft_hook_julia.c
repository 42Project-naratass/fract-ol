#include "../fractol.h"

int	ft_hook_julia(void *param)
{
    t_data	*img;

    img = param;
    img->czr = -0.50916;
    img->czi = -0.56277;
    if (img->need_render)
    {
	img = param;
	plot_julia(img);
	img->curr_pass++;
	if (img->curr_pass > 4)
	{
	    img->need_render = false;
	    img->curr_pass = 0;
	}
    }
    return (0);
}
