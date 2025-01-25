/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:07:11 by luis              #+#    #+#             */
/*   Updated: 2025/01/25 23:34:45 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

# define NUM_IMAGES 8

# define BUFFER_SIZE 1

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

void	init_data(t_mlx_data *data);

int		render_map(t_map *map, t_mlx_data *data);

int		parse_map(t_mlx_data *data);

int		close_window(t_mlx_data *data);

int		check_map_size(t_mlx_data *data);

int		count_collectibles(t_mlx_data *data);

int		is_traversable(int x, int y, t_mlx_data *data, int **is_visited);

void	dfs(int x, int y, t_mlx_data *data, int **is_visited);

void	find_player_pos(t_mlx_data *data, int *x, int *y);

void	init_visited(t_mlx_data *data, int **is_visited);

int		count_collec(t_mlx_data *data, int **is_visited);

int		check_map(t_mlx_data *data);

int		is_path_possible(t_mlx_data *data);

void	print_error_free(t_mlx_data *data, char *s);

void	update_print_moves(t_mlx_data *data);

int		key_hook(int keycode, t_mlx_data *data);

void	ft_free(char **res);

void	move(int x, int y, t_mlx_data *data);

void	determin_movement(t_mlx_data *data, int keycode);

void	check_player_starting(t_mlx_data *data, char c, int i, int j);

int		can_exit(t_mlx_data *data);

#endif