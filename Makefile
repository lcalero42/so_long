CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = so_long

SRCS = main.c
HEADERS = so_long.h libft/libft.h

OBJS_DIR = objects/
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all : $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME) : $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

$(OBJS_DIR)/%.o: %.c ${HEADERS}
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT): ${HEADERS}
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