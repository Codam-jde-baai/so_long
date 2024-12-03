PROJECT := so_long
CC := gcc
CFLAGS := -Wall -Wextra -Werror
MLX42FLAGS := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
## CODAM -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
## NON CODAM :  -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
NAME := so_long
LIBFT := ./libft_getnl/libft.a
MLX42 := ./MLX42/build/libmlx42.a
INCLUDE := -I./include
SRC :=  ./src/so_long.c \
		./src/utils.c \
		./src/initialize_structs.c \
		./src/read_map.c \
		./src/verify_map.c \
		./src/verify_paths.c \
		./src/load_image.c \
		./src/key_hooks.c \
		./src/update_game.c \
		./src/actions.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo " -- COMPILING SO_LONG -- \n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42) $(MLX42FLAGS)

$(LIBFT):
	@$(MAKE) -C ./libft_getnl

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	@$(MAKE) clean -C ./libft_getnl
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ./libft_getnl
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re