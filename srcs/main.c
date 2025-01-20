/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:55:27 by luis              #+#    #+#             */
/*   Updated: 2025/01/20 16:39:07 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int close_window(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx ,data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
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

	data.mlx = mlx_init();
	data.img.img = mlx_xpm_file_to_image(data.mlx, "ressources/background.xpm", &data.img.width, &data.img.height);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
