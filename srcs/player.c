/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:35:25 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/23 22:20:47 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void	determin_movement(t_mlx_data *data, int keycode)
{
	if (keycode == 119)
		move(0, -64, data);
	if (keycode == 115)
		move(0, 64, data);
	if (keycode == 97)
		move(-64, 0, data);
	if (keycode == 100)
		move(64, 0, data);
}

static int	check_move(int x, int y, t_mlx_data *data)
{
	if (x > 0
		&& data->map.grid[data->player.grid_y][data->player.grid_x + 1] == '1')
		return (0);
	if (x < 0
		&& data->map.grid[data->player.grid_y][data->player.grid_x - 1] == '1')
		return (0);
	if (y > 0
		&& data->map.grid[data->player.grid_y + 1][data->player.grid_x] == '1')
		return (0);
	if (y < 0
		&& data->map.grid[data->player.grid_y - 1][data->player.grid_x] == '1')
		return (0);
	return (1);
}

static void	determin_player_image(int x, int y, t_mlx_data *data)
{
	if (x > 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[5].img, data->player.pos_x, data->player.pos_y);
	if (x < 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[6].img, data->player.pos_x, data->player.pos_y);
	if (y > 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[3].img, data->player.pos_x, data->player.pos_y);
	if (y < 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[4].img, data->player.pos_x, data->player.pos_y);
}

void	move(int x, int y, t_mlx_data *data)
{
	determin_player_image(x, y, data);
	if (!check_move(x, y, data))
		return ;
	mlx_put_image_to_window(data->mlx, data->win,
		data->images[0].img, data->player.pos_x, data->player.pos_y);
	data->player.pos_x += x;
	data->player.pos_y += y;
	if (x > 0)
		data->player.grid_x++;
	if (x < 0)
		data->player.grid_x--;
	if (y > 0)
		data->player.grid_y++;
	if (y < 0)
		data->player.grid_y--;
	determin_player_image(x, y, data);
}

/*This function is used in the map parsing and checks
where the player starts and initialize its positions*/
void	check_player_starting(t_mlx_data *data, char c, int i, int j)
{
	if (c == 'P')
	{
		data->player.grid_x = j;
		data->player.grid_y = i;
		printf("%d\n%d\n", data->player.pos_x, data->player.pos_y);
	}
}
