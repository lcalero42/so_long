CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = so_long

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
CYAN = \033[36m
BOLD = \033[1m

SRCS = srcs/main.c srcs/init_data.c srcs/parse_map.c libft/get_next_line.c \
       srcs/close_window.c srcs/hook_handling.c srcs/player.c srcs/map_checkers.c \
       srcs/print_error_free.c srcs/collectibles.c srcs/is_path_possible.c \
       srcs/is_path_possible_utils.c srcs/rendering_utils.c libft/ft_bzero.c \
       libft/ft_strlen.c libft/ft_split.c libft/ft_itoa.c libft/ft_putnbr_fd.c \
       libft/ft_putstr_fd.c libft/ft_memcpy.c libft/ft_strdup.c libft/ft_strchr.c \
       libft/ft_calloc.c libft/ft_putchar_fd.c libft/ft_strncmp.c srcs/loop.c \
	   srcs/player_rendering.c srcs/map_rendering.c
HEADERS = includes/so_long.h libft/libft.h
LIBFT_HEADER = libft/libft.h

OBJS_DIR = objects/
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(MLX_LIB) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "$(BOLD)$(BLUE)Linking $(NAME)...$(RESET)"
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(OBJS) $(MLX_FLAGS)

$(OBJS_DIR)%.o: srcs/%.c ${HEADERS}
	mkdir -p $(OBJS_DIR)
	@echo "$(BOLD)$(GREEN)Compiling$(RESET) $<..."
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT): ${LIBFT_HEADER}
	@echo "$(BOLD)$(CYAN)Building libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) all

$(MLX_LIB):
	@echo "$(BOLD)$(CYAN)Building minilibx-linux...$(RESET)"
	$(MAKE) -C $(MLX_DIR)

clean:
	@echo "$(BOLD)$(RED)Cleaning object files...$(RESET)"
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "Cleaning binaries..."
	rm -f $(NAME)
	rm -f $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re all fclean clean
