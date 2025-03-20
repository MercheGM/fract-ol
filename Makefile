CC          = cc
CFLAGS      = -g3 -fsanitize=address -I$(PATH_SRC)
CFLAGS_MLX  = -ldl -lglfw -pthread -lm

RM          = @rm -f

PATH_LIBFT  = libft/
PATH_SRC    = src/
PATH_OBJ    = obj/

MLX_DIR         = MLX42/
MLX_BUILD_DIR   = MLX42/build/

NAME            = fractol
NAME_LIBFT      = libftprintf.a
NAME_LIBMLX     = libmlx42.a
NAME_INC		= fractol.h

LIBFT   = $(PATH_LIBFT)$(NAME_LIBFT)
LIBMLX  = $(MLX_BUILD_DIR)$(NAME_LIBMLX)

INC	=	$(PATH_SRC)$(NAME_INC)
SRC	=	$(PATH_SRC)color_utils.c  \
		$(PATH_SRC)colors.c \
		$(PATH_SRC)fractol.c \
		$(PATH_SRC)hook.c \
		$(PATH_SRC)inputs.c \
		$(PATH_SRC)julia.c \
		$(PATH_SRC)main.c \
		$(PATH_SRC)mandelbrot.c \
		$(PATH_SRC)utils.c \
		$(PATH_SRC)window.c \
		$(PATH_SRC)zoom.c
OBJ	=	$(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRC))

all: $(LIBFT) $(LIBMLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

$(LIBMLX):
	@cmake -DDEBUG=1 $(MLX_DIR) -B $(MLX_BUILD_DIR) && cmake --build $(MLX_BUILD_DIR) -j4

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(INC) | $(PATH_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJ):
	@mkdir -p $(PATH_OBJ)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(CFLAGS_MLX) -o $(NAME)

clean:
	$(RM) *.o
	$(MAKE) clean -C $(PATH_LIBFT)
	@cmake --build $(MLX_BUILD_DIR) --target clean || true

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(PATH_LIBFT)
	$(RM) -r $(MLX_BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
