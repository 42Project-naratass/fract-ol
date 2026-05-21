#include "../fractol.h"

t_complex	convert_to_complex(t_data *img, const int p_x, const int p_y)
{
    t_complex	complex;

    complex.real = X_MIN + (p_x / WIDTH) * (X_MAX - X_MIN);
    complex.i = Y_MAX - (p_y / HEIGHT) * (Y_MAX- Y_MIN);
    complex.real = (img->m_x - complex.real) / img->zoom;
    complex.i = (img->m_y - complex.i) / img->zoom;
    return (complex);
}
