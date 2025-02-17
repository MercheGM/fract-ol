CC = cc
CFLAGS = -g3
#CFLAGS = -Wall -Werror -Wextra
#CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address,undefined,leak
CFLAGS_MLX = -lmlx -lXext -lX11

RM = @rm -f

PATH_LIBFT = libftprintf/
PATH_MLX = minilibx-linux/
PATH_OBJ = obj/
PATH_SRC = src/

NAME = fractol
NAME_LIBFT = libftprintf.a
NAME_LIBMLX = libmlx_Linux.a

LIBFT = $(PATH_LIBFT)$(NAME_LIBFT)
LIBMLX = $(PATH_MLX)$(NAME_LIBMLX)

SRC   = $(wildcard $(PATH_SRC)/*.c)
OBJ   = $(patsubst $(PATH_SRC)/%.c, $(PATH_OBJ)/%.o, $(SRC))

all : $(LIBFT) $(LIBMLX) $(NAME) 

$(LIBFT) :
	$(MAKE) -C $(PATH_LIBFT)

$(LIBMLX) :
	$(MAKE) -C $(PATH_MLX)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(CFLAGS_MLX) -o $(NAME)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	$(RM) $(NAME) 
	$(RM) $(LIBFT) 
	$(RM) $(LIBMLX) 

clean:
	$(RM) *.o
	$(MAKE) clean -C $(PATH_MLX)
	$(MAKE) clean -C $(PATH_LIBFT)

re: fclean all

.PHONY : all bonus clean fclean re