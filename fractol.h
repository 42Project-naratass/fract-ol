/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naratass <naratass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:24:26 by naratass          #+#    #+#             */
/*   Updated: 2026/05/26 02:07:27 by naratass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include "ft_printf.h"

# define MAX_ITER 150
# define WIDTH 1920.0
# define HEIGHT 1080.0
# define MAX_ZOOM 10000000

// KEY CODES
# define ESC 65307
# define UP 38
# define DOWN 40
# define LEFT 37
# define RIGHT 39
# define W 119
# define A 97
# define S 115
# define D 100
# define R 114
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// MOUSECODE
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_data
{
	char	*name;
	void	*mlx;	
	void	*mlx_win;
	void	*img;
	size_t	curr_pass;
	bool	need_render;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	size_t	max_iter;
	int		c_x; // mouse center
	int		c_y; // screen center
	double	x_offset;
	double	y_offset;
	double	czi; // const z.i
	double	czr; // const z.rA
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}		t_data;

typedef struct s_pcor
{
	int	p_x;
	int	p_y;
}	t_pcor;

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct s_sqr
{
	double	xsqr;
	double	ysqr;
}	t_sqr;

// plot
void		init_mlx(t_data *img);
void		init_fractol(t_data *img);
void		my_mlx_pixel_put(t_data *data, const int p_x, const int p_y,
				int color);
void		render_resolution(t_data *img, size_t(*fractol)(t_data*, int, int),
				size_t reso_scale);

// mandelbrot
int			ft_hook_mandelbrot(void *param);
size_t		calc_mandelbrot(t_data *img, const int p_x, const int p_y);
void		plot_mandelbrot(t_data *img);

// julia
int			ft_hook_julia(void *param);
size_t		calc_julia(t_data *img, const int p_x, const int p_y);
void		plot_julia(t_data *img);

// math
uint32_t	get_color(const int iter);
void		zoom(t_data *fractol, const int x, const int y, const int zoom);

// event
int			ft_close_win(t_data *img);
int			ft_key_hook(int key_code, void *data);
int			ft_mouse_hook(int mouse_code, int x, int y, void *param);

// utils
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
bool			is_digit(char c);
bool			is_space(char c);
double			ft_atof(char *nbtr);
double			ft_strtod(char *str, char **endptr);
#endif
