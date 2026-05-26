NAME := fractol

SRC :=  ./fractol.c
SRC += 	./plot/init_mlx.c \
	./plot/init_fractol.c \
	./plot/my_mlx_pixel_put.c \
	./plot/render_resolution.c
SRC += 	./mandelbrot/plot_mandelbort.c \
	./mandelbrot/ft_hook_mandelbrot.c \
	./mandelbrot/calc_mandelbrot.c
SRC += ./math/zoom.c \
	./math/get_color.c
SRC += 	./event/ft_close_win.c \
	./event/ft_mouse_hook.c \
	./event/ft_key_hook.c
SRC +=	./utils/ft_tolower.c \
	./utils/ft_strncmp.c
SRC += 	./julia/plot_julia.c \
	./julia/ft_hook_julia.c \
	./julia/calc_julia.c
OBJS := $(SRC:.c=.o)

CC = cc

ORIG_CFLAGS := $(CFLAGS)
CFLAGS += -Wall -Werror -Wextra
CFLAGS += -O2 -march=native
CFLAGS += -g3 -fsanitize=address,undefined
CFLAGS += -Iminilibx -Ift_printf -I.
LDFLAGS = -Lminilibx -Lft_printf
LDLIBS := -lm -lmlx -lX11 -lftprintf -lXext
unexport CFLAGS LDFLAGS LDLIBS

all : $(NAME)
clean :
	$(MAKE) -C minilibx clean
	$(MAKE) -C ft_printf clean
	$(RM) $(OBJS) $(DEPS)

fclean : clean
	rm -f minilibx/libmlx.a
	$(MAKE) -C ft_printf fclean
	$(RM) $(OBJS) $(NAME)

re : fclean all

minilibx/libmlx.a:
	$(MAKE) -C minilibx all

ft_printf/libftprintf.a :
	CFLAGS=$(ORIG_CFLAGS) $(MAKE) -C ft_printf all

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME) : $(OBJS) | minilibx/libmlx.a ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.NOTPARALLEL: re
.PHONY: all clean fclean re libft
