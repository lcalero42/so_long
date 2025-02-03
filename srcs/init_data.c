/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:23:53 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 13:21:39 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_player_images(t_mlx_data *data);
static void	init_images(t_mlx_data *data);
static void	check_images_init(t_mlx_data *data);

/*This function initializes all the data needed for the
logic of the game (map, images...)*/
void	init_data(t_mlx_data *data, char *file_name)
{
	ft_bzero(data, sizeof(t_mlx_data));
	data->keycode = S_KEY;
	data->mlx = mlx_init();
	if (!data->mlx)
		print_error_free(data, "Error initializing mlx\n");
	parse_map(data, file_name);
	data->collectibles = count_collectibles(data);
	check_map(data);
	init_images(data);
	check_images_init(data);
	data->player.current_image = data->images[3];
	data->window_x = IMG_SIZE * data->map.width;
	data->window_y = IMG_SIZE * data->map.height;
	data->win = mlx_new_window(data->mlx, data->window_x,
			data->window_y, "So_long");
	if (!data->win)
		print_error_free(data, "Error initializing window\n");
	ft_putstr_fd("\e[0;32mGame Is Lauching...\n\e[0m", 1);
}

/*This function initializes all the different images of
the player in the data*/
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

/*This function initializes all the different images 
in the data*/
static void	init_images(t_mlx_data *data)
{
	data->images[0].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/floor.xpm",
			&data->images[0].width,
			&data->images[0].height);
	data->images[1].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/tree.xpm",
			&data->images[1].width,
			&data->images[1].height);
	data->images[2].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/ball.xpm",
			&data->images[2].width,
			&data->images[2].height);
	init_player_images(data);
	data->images[7].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/hole.xpm",
			&data->images[7].width,
			&data->images[7].height);
}

/*Checks if all images have been initialized correctly*/
static void	check_images_init(t_mlx_data *data)
{
	int	i;

	ft_putstr_fd("Checking image initialization...\n", 1);
	i = 0;
	while (i < NUM_IMAGES)
	{
		if (!data->images[i].img)
			print_error_free(data,
				"Error\nAn image has not been initialized\n");
		i++;
	}
}
