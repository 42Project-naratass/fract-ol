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
CFLAGS += -Ilibft -Iminilibx -Ift_printf -I.
LDFLAGS = -Llibft -Lminilibx -Lft_printf
LDLIBS := -lft -lm -lmlx -lX11 -lftprintf -lXext
unexport CFLAGS LDFLAGS LDLIBS

all : $(NAME)
clean :
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx clean
	$(RM) $(OBJS) $(DEPS)

fclean : clean
	$(RM) $(OBJS) $(NAME)

re : fclean all

minilibx/libmlx.a:
	$(MAKE) -C minilibx all

libft/libft.a :
	CFLAGS='$(ORIG_CFLAGS)' $(MAKE) -C libft all

ft_printf/libftprintf.a :
	CFLAGS='$(ORIG_CFLAGS)' $(MAKE) -C libftprintf all

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME) : $(OBJS) | libft/libft.a minilibx/libmlx.a ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.NOTPARALLEL: re
.PHONY: all clean fclean re libft
