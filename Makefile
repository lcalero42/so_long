CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = so_long
NAME_BONUS = so_long_bonus

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
CYAN = \033[36m
BOLD = \033[1m

# Source files
SRCS = srcs/main.c srcs/init_data.c srcs/parse_map.c libft/get_next_line.c \
       srcs/close_window.c srcs/hook_handling.c srcs/player.c srcs/map_checkers.c \
       srcs/print_error_free.c srcs/collectibles.c srcs/is_path_possible.c \
       srcs/is_path_possible_utils.c srcs/rendering_utils.c libft/ft_bzero.c \
       libft/ft_strlen.c libft/ft_split.c libft/ft_itoa.c libft/ft_putnbr_fd.c \
       libft/ft_putstr_fd.c libft/ft_memcpy.c libft/ft_strdup.c libft/ft_strchr.c \
       libft/ft_calloc.c libft/ft_putchar_fd.c libft/ft_strncmp.c srcs/loop.c \
       srcs/player_rendering.c srcs/map_rendering.c

SRCS_BONUS = srcs_bonus/main_bonus.c srcs_bonus/init_data_bonus.c srcs_bonus/parse_map_bonus.c \
       srcs_bonus/close_window_bonus.c srcs_bonus/hook_handling_bonus.c srcs_bonus/player_bonus.c \
       srcs_bonus/map_checkers_bonus.c srcs_bonus/is_path_possible_bonus.c \
       srcs_bonus/print_error_free_bonus.c srcs_bonus/collectibles_bonus.c \
       srcs_bonus/is_path_possible_utils_bonus.c srcs_bonus/rendering_utils_bonus.c libft/ft_bzero.c \
       libft/ft_strlen.c libft/ft_split.c libft/ft_itoa.c libft/ft_putnbr_fd.c \
       libft/ft_putstr_fd.c libft/ft_memcpy.c libft/ft_strdup.c libft/ft_strchr.c \
       libft/ft_calloc.c libft/ft_putchar_fd.c libft/ft_strncmp.c srcs_bonus/loop_bonus.c \
       srcs_bonus/player_rendering_bonus.c srcs_bonus/map_rendering_bonus.c libft/get_next_line.c

HEADERS = includes/so_long.h libft/libft.h
BONUS_HEADERS = includes/so_long_bonus.h libft/libft.h

OBJS_DIR = objects/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)
BONUS_OBJS = $(SRCS_BONUS:%.c=$(OBJS_DIR)%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(MLX_LIB) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "$(BOLD)$(BLUE)Linking $(NAME)...$(RESET)"
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(OBJS) $(MLX_FLAGS)

bonus: $(MLX_LIB) $(LIBFT) $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	@echo "$(BOLD)$(BLUE)Linking $(NAME_BONUS)...$(RESET)"
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(LIBFT) $(BONUS_OBJS) $(MLX_FLAGS)

# Ensure subdirectories exist before compiling
$(OBJS_DIR)%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@echo "$(BOLD)$(GREEN)Compiling$(RESET) $<..."
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)srcs_bonus/%.o: srcs_bonus/%.c $(BONUS_HEADERS)
	@mkdir -p $(dir $@)
	@echo "$(BOLD)$(GREEN)Compiling bonus$(RESET) $<..."
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/libft.h
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
	@echo "$(BOLD)$(RED)Cleaning binaries...$(RESET)"
	rm -f $(NAME) $(NAME_BONUS)
	rm -f $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re all fclean clean bonus
