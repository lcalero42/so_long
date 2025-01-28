/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:07:11 by luis              #+#    #+#             */
/*   Updated: 2025/01/28 17:59:59 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

# define NUM_IMAGES 8

# define BUFFER_SIZE 1

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
	int	pos_x;
	int	pos_y;
	int	grid_x;
	int	grid_y;
	int	collectibles;
	int	nb_moves;
}	t_player;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_image		images[NUM_IMAGES];
	t_map		map;
	t_player	player;
	int			collectibles;
}	t_mlx_data;

//data  initializing
void	init_data(t_mlx_data *data, char *file_name);

void	find_player_pos(t_mlx_data *data, int *x, int *y);

void	check_player_starting(t_mlx_data *data, char c, int i, int j);

int		count_collectibles(t_mlx_data *data);

//map parsing/rendering functions
int		render_map(t_map *map, t_mlx_data *data);

int		parse_map(t_mlx_data *data, char *file_name);

int		check_map(t_mlx_data *data);

int		check_map_size(t_mlx_data *data);

void	skip_newlines(char **line, int fd);

//-----------path_checking
int		is_path_possible(t_mlx_data *data);

void	dfs(int x, int y, t_mlx_data *data, int **is_visited);

void	init_visited(t_mlx_data *data, int **is_visited);

int		is_traversable(int x, int y, t_mlx_data *data, int **is_visited);

int		count_possible_collec(t_mlx_data *data, int **is_visited);

//player functions
void	move(int x, int y, t_mlx_data *data);

void	determin_movement(t_mlx_data *data, int keycode);

void	update_print_moves(t_mlx_data *data);

int		can_exit(t_mlx_data *data);

//window/error handling
int		close_window(t_mlx_data *data);

void	player_win(t_mlx_data *data);

void	print_error_free(t_mlx_data *data, char *s);

int		key_hook(int keycode, t_mlx_data *data);

void	ft_free(char **res);

#endif