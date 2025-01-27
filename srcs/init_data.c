/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:23:53 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/27 19:46:29 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include <string.h>

static void	init_player_images(t_mlx_data *data)
{
	data->images[3].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/player.xpm",
			&data->images[3].width,
			&data->images[3].height);
	data->images[4].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/player_2.xpm",
			&data->images[4].width,
			&data->images[4].height);
	data->images[5].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/player_3.xpm",
			&data->images[5].width,
			&data->images[5].height);
	data->images[6].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/player_4.xpm",
			&data->images[6].width,
			&data->images[6].height);
}

static void	init_images(t_mlx_data *data)
{
	data->images[0].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/floor.xpm",
			&data->images[0].width,
			&data->images[0].height);
	data->images[1].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/bush.xpm",
			&data->images[1].width,
			&data->images[1].height);
	data->images[2].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/bottle.xpm",
			&data->images[2].width,
			&data->images[2].height);
	init_player_images(data);
	data->images[7].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/hole.xpm",
			&data->images[7].width,
			&data->images[7].height);
}

void	init_data(t_mlx_data *data, char *file_name)
{
	memset(data, 0, sizeof(t_mlx_data));
	data->map.grid = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error_free(data, "Error initializing mlx\n");
	parse_map(data, file_name);
	data->collectibles = count_collectibles(data);
	check_map(data);
	data->win = mlx_new_window(data->mlx, 64 * data->map.width,
			64 * data->map.height, "so_long");
	if (!data->win)
		print_error_free(data, "Error initializing window\n");
	init_images(data);
}
