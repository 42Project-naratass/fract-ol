#include "../fractol.h"

t_complex	offset_cal(const int p_x, const int p_y)
{
    t_complex	offset;

    offset.real = X_MIN + (p_x / WIDTH) * (X_MAX - X_MIN);
    offset.i = Y_MAX - (p_y / HEIGHT) * (Y_MAX- Y_MIN);
    return (offset);
}
