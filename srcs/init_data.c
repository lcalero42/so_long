/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:23:53 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/24 00:25:16 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	pre_init_images(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGES)
	{
		data->images[i].img = NULL;
		i++;
	}
}

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

void	init_data(t_mlx_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map.grid = NULL;
	pre_init_images(data);
	data->mlx = mlx_init();
	parse_map(&data->map);
	check_map(data);
	data->win = mlx_new_window(data->mlx, 64 * data->map.width,
			64 * data->map.height, "so_long");
	init_images(data);
	data->camera.pos_x = 0;
	data->camera.pos_y = 0;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.collectibles = 0;
	data->num_collectibles = count_collectibles(data);
}
