CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = so_long

SRCS = srcs/main.c srcs/init_data.c srcs/parse_map.c libft/get_next_line.c \
       srcs/close_window.c srcs/hook_handling.c srcs/player.c srcs/map_checkers.c \
       srcs/print_error_free.c srcs/collectibles.c srcs/is_path_possible.c \
       srcs/is_path_possible_utils.c srcs/rendering_utils.c libft/ft_bzero.c \
       libft/ft_strlen.c libft/ft_split.c libft/ft_itoa.c libft/ft_putnbr_fd.c \
       libft/ft_putstr_fd.c libft/ft_memcpy.c libft/ft_strdup.c libft/ft_strchr.c \
       libft/ft_calloc.c libft/ft_putchar_fd.c
HEADERS = includes/so_long.h libft/libft.h

OBJS_DIR = objects/
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)%.o)

LIBFT_DIR = libft
LIBFT_SRCS = $(LIBFT_DIR)/ft_bzero.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_split.c \
             $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_putnbr_fd.c $(LIBFT_DIR)/ft_putstr_fd.c \
             $(LIBFT_DIR)/ft_memcpy.c $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_strchr.c \
             $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_putchar_fd.c
LIBFT_OBJS = $(LIBFT_SRCS:$(LIBFT_DIR)/%.c=$(OBJS_DIR)%.o)
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking $(NAME)..."
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

$(OBJS_DIR)%.o: srcs/%.c ${HEADERS}
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)%.o: $(LIBFT_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling $< from libft..."
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_OBJS)
	@echo "Building libft..."
	@$(AR) rcs $(LIBFT) $(LIBFT_OBJS)

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
	@rm -f $(LIBFT)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re all fclean clean
