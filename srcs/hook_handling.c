/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:22:05 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/22 20:55:46 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

static void	determin_movement(int *i, int *j, int keycode, t_mlx_data *data)
{
	if (keycode == 119 && *i > 0)
		*i = *i - 1;
	if (keycode == 97 && *j > 0)
		*j = *j - 1;
	if (keycode == 115 && *i < data->map.height)
		*i = *i + 1;
	if (keycode == 100 && *j < data->map.width)
		*j = *j + 1;
}

static void	redraw_from(t_mlx_data *data, int keycode, int *i, int *j)
{
	int		x;
	int		y;
	int		temp_i;
	int		temp_j;
	
	y = 0;
	determin_movement(i, j, keycode, data);
	temp_i = *i;
	temp_j = *j;
	while (data->map.grid[*i])
	{
		x = 0;
		*j = 0;
		while (data->map.grid[*i][*j])
		{
			if (data->map.grid[*i][*j] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images[1].img, x, y);
			else if (data->map.grid[*i][*j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images[2].img, x, y);
			x += 64;
			(*j)++;
		}
		y += 64;
		(*i)++;
	}
	*i = temp_i;
	*j = temp_j;
}

static void	update_camera(t_mlx_data *data, int keycode)
{
	static int	i = 0;
	static int	j = 0;
	
	mlx_put_image_to_window(data->mlx, data->win,
					data->images[0].img, 0, 0);
	redraw_from(data, keycode, &i, &j);
}

//used to determin which key has been pressed
int	key_hook(int keycode, t_mlx_data *data)
{
	printf("%d !\n", keycode);
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		update_camera(data, keycode);
	return (0);
}
