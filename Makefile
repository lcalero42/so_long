CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = so_long

SRCS = srcs/main.c srcs/init_data.c srcs/parse_map.c libft/get_next_line.c \
       srcs/close_window.c srcs/hook_handling.c srcs/player.c srcs/map_checkers.c \
	   srcs/print_error_free.c srcs/collectibles.c
HEADERS = includes/so_long.h libft/libft.h

OBJS_DIR = objects/
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all : $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME) : $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

$(OBJS_DIR)%.o: srcs/%.c ${HEADERS}
	@mkdir -p $(OBJS_DIR) 
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR) all

$(MLX_LIB):
	@echo "Building minilibx-linux..."
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re all fclean clean
