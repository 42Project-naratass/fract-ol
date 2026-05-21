#include "../fractol.h"

t_complex	convert_to_complex(t_data *img, const int p_x, const int p_y)
{
    t_complex	complex;

    complex = offset_cal(p_x, p_y);
    complex.real = (img->m_x - complex.real) / img->zoom;
    complex.i = (img->m_y - complex.i) / img->zoom;
    return (complex);
}
