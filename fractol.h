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
# define w 119
# define a 97
# define s 115
# define d 100
# define r 114
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
    int		cx;
    int		cy;
    size_t	max_iter;
    int		m_x; // mouse coordinate
    int		m_y; // mouse coordinate
    double	x_offset;
    double	y_offset;
}		t_data;

typedef struct s_pcor
{
    int	x_c;
    int	y_c;
}		t_pcor;

typedef struct s_complex 
{
    double	real;
    double	i;
}		t_complex;

// plot
void	init_mlx(t_data *img);
void	init_fractol(t_data *img);
void	my_mlx_pixel_put(t_data *data, const int p_x, const int p_y, int color);
void	render_resolution(t_data *img, size_t(*fractol)(t_data*, int, int), size_t reso_scale);

// mandelbrot
int	ft_hook_mandelbrot(void *param);
size_t	calc_mandelbrot(t_data *img, const int p_x, const int p_y);
void	plot_mandelbrot(t_data *img);

// math
t_complex	offset_cal(const int p_x, const int p_y);
t_complex	convert_to_complex(t_data *img, const int p_x, const int p_y);
uint32_t	get_color(const int iter);

// event
int	ft_close_win(t_data *img);
int	ft_key_hook(int key_code, void *data);
int	ft_mouse_hook(int mouse_code, int x, int y, void *param);
void	zoom(t_data *fractol, const int x, const int y, const int zoom);

// utils
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_tolower(int c);

#endif
