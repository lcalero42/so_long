/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:36:58 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/31 17:08:45 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	put_right_image(char c, t_mlx_data *data, int x, int y);
static void	check_player_starting(t_mlx_data *data, char c, int i, int j);

/*This function get through all the elements of the map
and puts each time the corresponding image to the screen at
the right position*/
int	render_map(t_map *map, t_mlx_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	while (map->grid[i] && (i < MAX_HEIGHT))
	{
		j = 0;
		while (map->grid[i][j] && (j < MAX_WIDTH))
		{
			put_right_image(map->grid[i][j], data, x, y);
			check_player_starting(data, map->grid[i][j], i, j);
			j++;
			x += IMG_SIZE;
		}
		x = 0;
		y += IMG_SIZE;
		i++;
	}
	return (0);
}

/*This function checks the right image to put at a certain position
in the given map and puts it on the screen*/
static void	put_right_image(char c, t_mlx_data *data, int x, int y)
{
	if (c == '1' && data->images[1].img)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[1].img, x, y);
	else if (c == 'C' && data->images[2].img)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[2].img, x, y);
	else if (c == 'P' && data->images[3].img)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			get_player_texture(data->keycode, data).img, x, y);
		data->player.pos_x = x;
		data->player.pos_y = y;
	}
	else if (c == 'E' && data->images[7].img)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[7].img, x, y);
	else if (c == '0' && data->images[0].img)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[0].img, x, y);
	else if (c == 'K' && data->images[8].img)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[8].img, x, y);
	else
		print_error_free(data, "Error\n Failed to load image\n");
}

/*This function is used in the map parsing and checks
where the player starts and initialize its positions*/
static void	check_player_starting(t_mlx_data *data, char c, int i, int j)
{
	if (c == 'P')
	{
		data->player.grid_x = j;
		data->player.grid_y = i;
	}
}
