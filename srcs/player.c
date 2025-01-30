/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:35:25 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/30 18:52:15 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_move(int x, int y, t_mlx_data *data);
static int	can_exit(t_mlx_data *data);

/*This function applies all the moving logic and updates the
coordinates of the player in the screen and in the grid*/
void	move(int x, int y, t_mlx_data *data, int keycode)
{
	save_player_image(keycode, data);
	if (!check_move(x, y, data))
		return ;
	data->player.nb_moves++;
	update_print_moves(data);
	data->player.pos_x += x;
	data->player.pos_y += y;
	data->map.grid[data->player.grid_y][data->player.grid_x] = '0';
	if (x > 0)
		data->player.grid_x++;
	if (x < 0)
		data->player.grid_x--;
	if (y > 0)
		data->player.grid_y++;
	if (y < 0)
		data->player.grid_y--;
	if (data->map.grid[data->player.grid_y][data->player.grid_x] == 'C')
	{
		data->player.collectibles++;
		data->map.grid[data->player.grid_y][data->player.grid_x] = '0';
	}
	if (data->map.grid[data->player.grid_y][data->player.grid_x] == 'E')
		player_win(data);
}

/*This functions determins which movement has been processed and
calls the right moving logic in consequence*/
void	determin_movement(t_mlx_data *data, int keycode)
{
	if (keycode == W_KEY || keycode == UP_ARROW)
	{
		move(0, -IMG_SIZE, data, keycode);
		data->map.grid[data->player.grid_y][data->player.grid_x] = 'P';
	}
	if (keycode == S_KEY || keycode == DOWN_ARROW)
	{
		move(0, IMG_SIZE, data, keycode);
		data->map.grid[data->player.grid_y][data->player.grid_x] = 'P';
	}
	if (keycode == A_KEY || keycode == LEFT_ARROW)
	{
		move(-IMG_SIZE, 0, data, keycode);
		data->map.grid[data->player.grid_y][data->player.grid_x] = 'P';
	}
	if (keycode == D_KEY || keycode == RIGHT_ARROW)
	{
		move(IMG_SIZE, 0, data, keycode);
		data->map.grid[data->player.grid_y][data->player.grid_x] = 'P';
	}
}

/*This function checks if the player can move to the position where he
wants to move or not*/
static int	check_move(int x, int y, t_mlx_data *data)
{
	if (x > 0
		&& (data->map.grid[data->player.grid_y][data->player.grid_x + 1] == '1'
		|| (data->map.grid[data->player.grid_y][data->player.grid_x + 1] == 'E'
		&& !can_exit(data))))
		return (0);
	if (x < 0
		&& (data->map.grid[data->player.grid_y][data->player.grid_x - 1] == '1'
		|| (data->map.grid[data->player.grid_y][data->player.grid_x - 1] == 'E'
		&& !can_exit(data))))
		return (0);
	if (y > 0
		&& (data->map.grid[data->player.grid_y + 1][data->player.grid_x] == '1'
		|| (data->map.grid[data->player.grid_y + 1][data->player.grid_x] == 'E'
		&& !can_exit(data))))
		return (0);
	if (y < 0
		&& (data->map.grid[data->player.grid_y - 1][data->player.grid_x] == '1'
		|| (data->map.grid[data->player.grid_y - 1][data->player.grid_x] == 'E'
		&& !can_exit(data))))
		return (0);
	return (1);
}


/*This function returns if the player is allowed to take
the exit by checking his number of collectibles*/
static int	can_exit(t_mlx_data *data)
{
	return (data->player.collectibles == data->collectibles);
}
