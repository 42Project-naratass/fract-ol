NAME := fractol

SRC := $(wildcard *.c)
SRC += $(wildcard plot/*.c)
SRC += $(wildcard mandelbort/*.c)
SRC += $(wildcard math/*.c)
SRC += $(wildcard event/*.c)
OBJS := $(SRC:.c=.o)

CC = cc

ORIG_CFLAGS := $(CFLAGS)
CFLAGS += -Wall -Werror -Wextra
CFLAGS += -O2 -march=native
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
