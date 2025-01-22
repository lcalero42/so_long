/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:07:11 by luis              #+#    #+#             */
/*   Updated: 2025/01/22 20:42:29 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

# define IMG_BACKGROUND 0
# define IMG_OBSTACLE 1
# define IMG_COLLECTIBLE 2
# define IMG_EXIT 3
# define NUM_IMAGES 3

# define BUFFER_SIZE 1

typedef struct	s_image {
	void	*img;
	int		width;
	int		height;
}	t_image;

typedef struct	s_map {
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_mlx_data
{
    void	*mlx;
    void	*win;
    t_image	images[NUM_IMAGES];
	t_map	map;
}	t_mlx_data;

void	init_data(t_mlx_data *data);

int		render_map(t_map *map, t_mlx_data *data);

int		parse_map(t_map *map);

int		close_window(t_mlx_data *data);

int		key_hook(int keycode, t_mlx_data *data);

void	ft_free(char **res);

#endif