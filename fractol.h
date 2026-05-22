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

# define MAX_ITER 100
# define WIDTH 1920.0
# define HEIGHT 1080.0
# define X_MIN -1.6
# define X_MAX 1.6
# define Y_MIN -0.9
# define Y_MAX 0.9

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
# define R 15
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
void	init(t_data *img);
void	my_mlx_pixel_put(t_data *data, const int p_x, const int p_y, int color);
void	reso_x1(t_data *img);
void	reso_x2(t_data *img);
void	reso_x4(t_data *img);
void	reso_x8(t_data *img);

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

#endif
