/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:07:11 by luis              #+#    #+#             */
/*   Updated: 2025/02/03 13:05:46 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

# define NUM_IMAGES 9

# define NUM_ANIM 2
# define TOWARD_DIR 1
# define BACKWARD_DIR 0
# define LEFT_DIR 3
# define RIGHT_DIR 2

# define IMG_SIZE 64

# define MAX_WIDTH 60
# define MAX_HEIGHT 30

# define BUFFER_SIZE 1

# define WHITE 0xFFFFFF

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363
# define ESC_KEY 65307

//structs
typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
}	t_image;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		grid_x;
	int		grid_y;
	int		collectibles;
	int		nb_moves;
	t_image	current_image;
	t_image	animations[4][NUM_ANIM];
}	t_player;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_image		images[NUM_IMAGES];
	t_map		map;
	t_player	player;
	int			collectibles;
	int			window_x;
	int			window_y;
	int			keycode;
}	t_mlx_data;

//data  initializing
void	init_data(t_mlx_data *data, char *file_name);

void	find_player_pos(t_mlx_data *data, int *x, int *y);

int		count_collectibles(t_mlx_data *data);

void	init_animations(t_mlx_data *data);

//map parsing/rendering functions
int		render_map(t_map *map, t_mlx_data *data);

int		parse_map(t_mlx_data *data, char *file_name);

int		check_map(t_mlx_data *data);

void	skip_newlines(char **line, int fd);

void	check_end_of_file(char **line, int fd, char *res, t_mlx_data *data);

int		check_map_extension(char *s);

//-----------path_checking
int		is_path_possible(t_mlx_data *data);

void	dfs(int x, int y, t_mlx_data *data, int **is_visited);

void	init_visited(t_mlx_data *data, int **is_visited);

int		is_traversable(int x, int y, t_mlx_data *data, int **is_visited);

int		count_possible_collec(t_mlx_data *data, int **is_visited);

//player functions
void	move(int x, int y, t_mlx_data *data, int keycode);

void	determin_movement(t_mlx_data *data, int keycode);

//window/error handling
int		close_window(t_mlx_data *data);

void	player_win(t_mlx_data *data);

void	print_error_free(t_mlx_data *data, char *s);

int		key_hook(int keycode, t_mlx_data *data);

void	ft_free(char **res);

void	free_animations(t_mlx_data *data);

//rendering
int		loop(t_mlx_data *data);

void	save_player_image(int keycode, t_mlx_data *data);

t_image	render_player_texture(int keycode, t_mlx_data *data);

void	update_print_moves(t_mlx_data *data);

t_image	play_anim(t_mlx_data *data, int anim_index);

#endif