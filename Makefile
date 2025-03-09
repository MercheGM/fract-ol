CC          = cc
CFLAGS      = -g3 -fsanitize=address -I$(PATH_SRC)
# Opcionales:
# CFLAGS      = -Wall -Werror -Wextra
# CFLAGS      = -Wall -Werror -Wextra -g3 -fsanitize=address,undefined,leak

# Flags de enlace para MLX42 en Linux (ajusta según tu SO)
CFLAGS_MLX  = -ldl -lglfw -pthread -lm

RM          = @rm -f

# Rutas para libft y fuentes
PATH_LIBFT  = libft/
PATH_SRC    = src/
PATH_OBJ    = obj/

# Variables para MLX42
MLX_DIR         = MLX42/
MLX_BUILD_DIR   = MLX42/build/

NAME            = fractol
NAME_LIBFT      = libftprintf.a
NAME_LIBMLX     = libmlx42.a
NAME_INC		= fractol.h

LIBFT   = $(PATH_LIBFT)$(NAME_LIBFT)
LIBMLX  = $(MLX_BUILD_DIR)$(NAME_LIBMLX)

INC = $(PATH_SRC)$(NAME_INC)
SRC   = $(wildcard $(PATH_SRC)*.c)
OBJ   = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRC))

all: $(LIBFT) $(LIBMLX) $(NAME)

# Compilación de la libft
$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

# Compilación de MLX42 mediante CMake
$(LIBMLX):
	@cmake -DDEBUG=1 $(MLX_DIR) -B $(MLX_BUILD_DIR) && cmake --build $(MLX_BUILD_DIR) -j4

# Regla para compilar los objetos (.o)
$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(INC) | $(PATH_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJ):
	@mkdir -p $(PATH_OBJ)

# Enlaza el ejecutable final
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
