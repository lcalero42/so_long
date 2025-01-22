/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:55:27 by luis              #+#    #+#             */
/*   Updated: 2025/01/22 18:08:03 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int close_window(t_mlx_data *data)
{	
	int	i;

	i = 0;
	while (i < NUM_IMAGES)
	{
		if (data->images[i].img)
			mlx_destroy_image(data->mlx ,data->images[i].img);
		i++;
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_mlx_data *data)
{
	printf("%d !\n", keycode);
	if (keycode == 65307 || keycode == 17)
		close_window(data);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;
	t_map		map;

	parse_map(&map);
	init_data(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.images[0].img, 0, 0);
	parse_input(&map, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
