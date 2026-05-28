// #include "../fractol.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static void	beforedot(double *sum, char **nbtr)
{
    while (**nbtr != '\0' && is_digit(**nbtr))
    {
	*sum = *sum * 10.0 + (**nbtr - '0');
	(*nbtr)++;
    }
}

static void	afterdot(double *sum, char **nbtr, int *e)
{
    if (**nbtr == '.')
    {
	(*nbtr)++;
	while (**nbtr != '\0' && is_digit(**nbtr))
	{
	    *sum = *sum * 10.0 + (**nbtr - '0');
	    (*nbtr)++;
	    (*e)--;
	}
    }
}

static void	apply_e(char **nbtr, int *e)
{
    int	sign;
    int	i;

    sign = 0;
    i = 0;
    if (**nbtr == 'e' || **nbtr == 'E')
    {
	(*nbtr)++;
	sign = 1;
	if (**nbtr == '+')
	    (*nbtr)++;
	else if (**nbtr == '-')
	{
	    sign *= -1;
	    (*nbtr)++;
	}
	while (is_digit(**nbtr))
	{
	    i = i * 10 + (**nbtr - '0');
	    (*nbtr)++;
	}
	*e += i * sign;
    }
}

double	ft_atof(char *nbtr)
{
    double	sum;
    int		e;

    sum = 0.0;
    e = 0;
    beforedot(&sum, &nbtr);
    afterdot(&sum, &nbtr, &e);
    apply_e(&nbtr, &e);
    while (e > 0)
    {
	sum *= 10.0;
	e--;
    }
    while (e < 0)
    {
	sum *= 0.1;
	e++;
    }
    return (sum);
}

