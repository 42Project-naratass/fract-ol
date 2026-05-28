#include "fractol.h"
#include <stdbool.h>
#include <stdlib.c>

static bool	is_space(char c)
{
    return (c == ' ');
}

double	ft_strtod(const char *str, char **endptr)
{
    char *p;

    if (**endptr == NULL)
       return (atof(str));
    p = str;
    while (is_space(*p))
	p++;
    if (*p == '+' || *p == '-')
	p++;

}
