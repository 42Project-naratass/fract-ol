/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 00:16:49 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 02:05:24 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	invalid_parameter(char *argv[])
{
    double	czi;
    double	czr;
    char	*endptr;

    if (ft_strncmp(argv[1], "julia", 6) == 0)
    {
	czr = ft_strtod(argv[2], &endptr);
	if (czr < -1.0 || czr > 1.0 || (czr == 0.0 && *endptr))
	{
	    ft_printf("Invalid argument range (range = [-1.0 - 1.0])");
	    exit(1);
	}
	czi = ft_strtod(argv[3], &endptr);
	if (czi < -1.0 || czi > 1.0 || (czi == 0.0 && *endptr))
	{
	    ft_printf("Invalid argument range (range = [-1.0 - 1.0])");
	    exit(1);
	}
    }
}

static void	invalid_input(int argc, char *argv[])
{
    if ((ft_strncmp(argv[1], "mandelbrot", 10) != 0 || argc != 2)
	    && (ft_strncmp(argv[1], "julia", 6) != 0 || argc != 4))
    {
	ft_printf("error: invalid format\nUse following format:\n\
    ./fractol mandelbrot\n\
    ./fractol julia <value[-1.0, 1.0]> <value[-1.0, 1.0]>\n");
	exit(0);
    }
}

static void	draw_fractol(t_data *img, char *argv[])
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		mlx_loop_hook(img->mlx, ft_hook_mandelbrot, img);
		img->x_offset = -0.5;
		img->y_offset = 0.0;
		img->name = 'm';
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		mlx_loop_hook(img->mlx, ft_hook_julia, img);
		printf("czr: %lf\nczi: %lf\n", ft_atof(argv[2]), ft_atof(argv[3]));
		img->czr = ft_atof(argv[2]);
		img->czi = ft_atof(argv[3]);
		img->name = 'j';
	}
}

int	main(int argc, char *argv[])
{
	t_data	img;

	if (argc > 1)
	{
		invalid_input(argc, argv);
		invalid_parameter(argv);
		init_mlx(&img);
		init_fractol(&img);
		mlx_key_hook(img.mlx_win, ft_key_hook, &img);
		mlx_mouse_hook(img.mlx_win, ft_mouse_hook, &img);
		mlx_hook(img.mlx_win, 17, 0L, ft_close_win, &img);
		draw_fractol(&img, argv);
		mlx_loop(img.mlx);
	}
	else
		ft_printf("error: invalid format\nUse following format:\n\
    ./fractol mandelbrot\n\
    ./fractol julia <value[-1.0, 1.0]> <value[-1.0, 1.0]>\n");
	return (0);
}
